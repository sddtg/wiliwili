#include <nlohmann/json.hpp>
#include <utility>

#include "bilibili.h"
#include "bilibili/util/http.hpp"
#include "bilibili/result/video_detail_result.h"


namespace bilibili {

    void BilibiliClient::get_video_detail(const std::string& bvid,
                                          const std::function<void(VideoDetailResult)>& callback,
                                          const ErrorCallback& error){
//        BilibiliClient::pool.enqueue([=]{
            HTTP::getResultAsync<VideoDetailResult>(Api::Detail,
                                 {{"bvid", std::string(bvid)}},
                                 callback, error);
//        });
    }

    void BilibiliClient::get_video_detail(const int aid,
                                          const std::function<void(VideoDetailResult)>& callback,
                                          const ErrorCallback& error){
//        BilibiliClient::pool.enqueue([=]{
            HTTP::getResultAsync<VideoDetailResult>(Api::Detail,
                            {{"aid",std::to_string(aid)}},
                            callback, error);
//        });
    }

    void BilibiliClient::get_video_pagelist(const std::string& bvid,
                                          const std::function<void(VideoDetailPageListResult Result)>& callback,
                                          const ErrorCallback& error){
//        BilibiliClient::pool.enqueue([=]{
            HTTP::getResultAsync<VideoDetailPageListResult>(Api::PlayPageList,
                                 {{"bvid", std::string(bvid)}},
                                 callback, error);
//        });
    }

    void BilibiliClient::get_video_pagelist(const int aid,
                                          const std::function<void(VideoDetailPageListResult)>& callback,
                                          const ErrorCallback& error){
//        BilibiliClient::pool.enqueue([=]{
            HTTP::getResultAsync<VideoDetailPageListResult>(Api::PlayPageList,
                            {{"aid",std::to_string(aid)}},
                            callback, error);
//        });
    }


    void BilibiliClient::get_video_url(const std::string& bvid, const int cid, const int qn,
                                       const std::function<void(VideoUrlResult)> &callback,
                                       const ErrorCallback &error) {
//        BilibiliClient::pool.enqueue([=] {
            HTTP::getResultAsync<VideoUrlResult>(Api::PlayInformation, {
                                    {"bvid",  std::string(bvid)},
                                    {"cid",   std::to_string(cid)},
                                    {"qn",    std::to_string(qn)},
                                    {"fourk", "1"},
                                    {"fnver", "0"}},
                            callback, error);
//        });
    }

    void BilibiliClient::get_video_url(const int aid, const int cid, const int qn,
                                       const std::function<void(VideoUrlResult)> &callback,
                                       const ErrorCallback &error) {
//        BilibiliClient::pool.enqueue([=] {
            HTTP::getResultAsync<VideoUrlResult>(Api::PlayInformation, {
                                         {"aid",   std::to_string(aid)},
                                         {"cid",   std::to_string(cid)},
                                         {"qn",    std::to_string(qn)},
                                         {"fourk", "1"},
                                         {"fnver", "0"}},
                                 callback, error);
//        });
    }


}