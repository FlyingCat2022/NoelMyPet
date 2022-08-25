//
//  dialog_text.h
//  Somnambulism
//
//  Created by 洪润孜 on 2022/8/14.
//

#ifndef dialog_text_h
#define dialog_text_h

Font chinese;
int* codepoints,cp_count;


enum emotion{
    something_to_say,
    happy_red,
    normal,
    sad,
    angry,
    struggled,
    happy,
    empty,
    noticing,
    to_say
}words = happy;

typedef struct Dialog{
    char words[256];
    enum emotion emo_d;
    int wait_max;
    int ask_delay;
    char ask [2][64];
    void(*func[2])(void);
    int result[2];
    int re_delay[2];
    int happy[2],happy_wait;
    int love[2],love_wait;
} Dialog;

enum {
    DialogSay,
    DialogAsk,
    DialogWaitToSay,
    DialogWaitToAsk,
    DialogNULL
}DialogState = DialogSay;

unsigned DialogDelayConter;


Dialog d[]={
    (Dialog){ //0
        .words = "您好～\n今天过得如何？ ",
        .emo_d = happy,
        .wait_max = 600,
        .ask_delay = 100,
        .ask = {"过得不错",
                "过得不太好"},
        .func = {NULL,
                NULL},
        .result = {1,
                2},
        .re_delay = {0,
                200},
        .happy = {5,
                -3},
        .happy_wait = -2,
        .love = {1,
                1},
        .love_wait = -7
    },
    (Dialog){ //1
        .words = "今后也要开开心心的哟~",
        .emo_d = happy,
        .wait_max = 600,
        .ask_delay = 0,
        .ask = {"嗯",
            "你也是！"},
        .func = {NULL,
            NULL},
        .result = {-1,
            -1},
        .happy = {3,
            5},
        .happy_wait = -2,
        .love = {1,
            2},
        .love_wait = -10
    },
    (Dialog){ //2
        .words = "为什么呢……为什么您不高兴呢……",
        .emo_d = sad,
        .wait_max = 600,
        .ask_delay = 0,
        .ask = {"遇到了一些困难",
            "没什么"},
        .func = {NULL,
            NULL},
        .result = {3,
            4},
        .re_delay = {30,
            60},
        .happy = {5,
            -5},
        .happy_wait = -5,
        .love = {1,
            1}
    },
    (Dialog){ //3
        .words = "……也许总会过去的吧……",
        .emo_d = empty,
        .wait_max = 600,
        .ask_delay = 0,
        .ask = {"共勉",
            "但愿吧"},
        .func = {NULL,
            NULL},
        .result = {-1,
            -1},
        .happy = {5,
            1},
        .happy_wait = -10,
        .love = {2,
            1}
    },
    (Dialog){ //4
        .words = "对不起……",
        .emo_d = sad,
        .wait_max = 600,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
        .result = {-1,
            -1},
        .func = {NULL,
            NULL},
        .happy_wait = -10
    },
    (Dialog){ //5
        .words = "早上好，祝您度过不错的一天～",
        .emo_d = happy,
        .wait_max = 600,
        .ask_delay = 0,
        .ask = {"你也一样",
            "谢谢"},
        .func = {NULL,
            NULL},
        .result = {-1,
            -1},
        .re_delay = {0,
            0},
        .happy = {4,
            4},
        .happy_wait = -2,
        .love = {1,
            1},
        .love_wait = -5
    },
    (Dialog){ //6
        .words = "晚上好，祝您明日依旧一帆风顺～",
        .emo_d = happy,
        .wait_max = 600,
        .ask_delay = 0,
        .ask = {"愿明日天河灿烂",
            "今天才刚刚开始哦～"},
        .func = {NULL,
            NULL},
        .result = {-1,
            7},
        .re_delay = {0,
            7},
        .happy = {5,
            2},
        .happy_wait = -2,
        .love = {1,
            1},
        .love_wait = -5
    },
    (Dialog){ //7
        .words = "诶诶诶诶诶诶诶？\n真的吗？",
        .emo_d = happy_red,
        .wait_max = 500,
        .ask_delay = 0,
        .ask = {"骗你的啦～",
            "晚上可不止有——"},
        .func = {NULL,
            NULL},
        .result = {-1,
            8},
        .re_delay = {0,
            0},
        .happy = {3,
            -1},
        .happy_wait = 1,
        .love = {1,
            2},
        .love_wait = -1
    },
    (Dialog){ //8
        .words = "不！可！以！",
        .emo_d = happy_red,
        .wait_max = 300,
        .ask_delay = 0,
        .ask = {"可·以·的",
            "——我没说做什么哟"},
        .func = {NULL,
            NULL},
        .result = {9,
            10},
        .re_delay = {0,
            0},
        .happy = {-5,
            4},
        .happy_wait = 2,
        .love = {-1,
            1},
        .love_wait = 1
    },
    (Dialog){ //9
        .words = "啊啊啊啊啊啊啊啊啊————",
        .emo_d = noticing,
        .wait_max = 600,
        .ask_delay = 2000,
        .ask = {"\0",
            "\0"},
        .func = {NULL,
            NULL},
        .result = {-1,
            -1},
        .re_delay = {0,
            0},
    },
    (Dialog){ //10
        .words = "诶？诶诶？\n对不起……",
        .emo_d = sad,
        .wait_max = 600,
        .ask_delay = 888,
        .ask = {"\0",
            "\0"},
        .func = {NULL,
            NULL},
        .result = {-1,
            -1},
        .re_delay = {0,
            0},
    },
    (Dialog){ //11
        .words = "十一点了诶？",
        .emo_d = something_to_say,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //12
        .words = "十一点了……还不睡吗……",
        .emo_d = sad,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"马上就睡了呢～",
            "嗯，还有很多事要做"},
        .func = {NULL,
            NULL},
        .result = {-1,
            13},
        .re_delay = {0,
            200},
    },
    (Dialog){ //13
        .words = "保重健康啊……",
        .emo_d = sad,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //14
        .words = "时间不早了啊……",
        .emo_d = something_to_say,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //15
        .words = "每天这个时候开始，姐姐那里就会出现奇怪的声音……",
        .emo_d = something_to_say,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    
    (Dialog){ //16
        .words = "*哈欠*\n晚上好……",
        .emo_d = something_to_say,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //17
        .words = "唔……\n还没有睡吗……加油！",
        .emo_d = something_to_say,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //18
        .words = "唔……\n啊……早点睡吧。",
        .emo_d = something_to_say,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //19
        .words = "*哈欠*",
        .emo_d = something_to_say,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //20
        .words = "这个时间\n*哈欠*\n魔物频繁出没……",
        .emo_d = normal,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //21
        .words = "午夜了吗……要加强巡逻了……",
        .emo_d = struggled,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //22
        .words = "午夜……真可怕啊，你还清醒吗？",
        .emo_d = struggled,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //23
        .words = "这么晚还不睡……\n加油……",
        .emo_d = something_to_say,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //24
        .words = "……就这么坚持到天明吗……",
        .emo_d = something_to_say,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //25~30
        .words = "这，这是几点啊！",
        .emo_d = angry,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //25~30
        .words = "*哈欠*\n还在吗……",
        .emo_d = normal,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //25~30
        .words = "现在还不睡……对身体不好吧",
        .emo_d = sad,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //25~30
        .words = "……我先睡了吗？\n对不起……",
        .emo_d = something_to_say,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //25~30
        .words = "晚……现在应当说早上好吗？",
        .emo_d = normal,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
    (Dialog){ //25~30
        .words = "居然可以不睡觉到这种程度吗……",
        .emo_d = normal,
        .wait_max = 6000,
        .ask_delay = 0,
        .ask = {"\0",
            "\0"},
    },
};

const int dialog_num = 30;

int night11[]={
    11,12,14,16,17,18
};

int night12[]={
    19,20,21,22,23,24
};

int night3[]={
    25,26,27,28,29,30
};

int dialog_meet[] = {0,5,7} , dialog_meet_len = 3;
int dialog_free[] = {} , dialog_now = 0;



#endif /* dialog_text_h */
