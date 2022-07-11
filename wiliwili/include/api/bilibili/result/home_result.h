//
// Created by fang on 2022/5/26.
//

#pragma once

#include "nlohmann/json.hpp"
#include "user_result.h"

using namespace std;

namespace bilibili {

    class VideoSimpleStateResult {
    public:
        int view;
        int danmaku;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(VideoSimpleStateResult, view, danmaku);


    class RecommendReasonResult {
    public:
        string content;
        int reason_type;
        // 3: 点赞多
        // 1: 关注
        // 0: 无 ？
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(RecommendReasonResult, content, reason_type);

    class RecommendVideoResult {
    public:
        int id;
        string bvid;
        int cid;
        string pic;
        string title;
        int duration;
        int pubdate;
        UserSimpleResult owner;
        VideoSimpleStateResult stat;
        int is_followed;
        RecommendReasonResult rcmd_reason;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(RecommendVideoResult, id, bvid, cid, pic, title, duration, pubdate, owner, stat, is_followed);

    typedef vector<RecommendVideoResult> RecommendVideoListResult;

    class RecommendVideoListResultWrapper {
    public:
        RecommendVideoListResult item;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(RecommendVideoListResultWrapper, item);

};