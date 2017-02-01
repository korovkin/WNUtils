#include <glog/logging.h>

#include "WNUtils.h"

int main(int argc, char** argv)
{
    google::InitGoogleLogging("wnutils");
    gflags::SetVersionString("whynot");
    google::ParseCommandLineFlags(&argc, &argv, true);
    FLAGS_logtostderr = true;

    LOG(INFO) << "hello!";
    
    // map:
    {
        std::map<int, std::string> m{
            {1, "one"},
            {2, "two"}
        };
        
        CHECK(wn::contains_key(m, 1));
        CHECK(wn::contains_key(m, 2));
        CHECK_EQ(wn::contains_key(m, 3), false);
        
        std::string v;
        bool found = false;

        found = wn::get_key(m, 1, v, std::string("x"));
        CHECK(found);
        CHECK_EQ(v, "one");
        
        found = wn::get_key(m, 2, v, std::string("x"));
        CHECK(found);
        CHECK_EQ(v, "two");
        
        found = wn::get_key(m, 7, v, std::string("seven"));
        CHECK(!found);
        CHECK_EQ(v, "seven");
    }

    // int map:
    {
        std::map<int, int> mm{
            {1, 1},
            {2, 2},
        };
        CHECK(wn::contains_key(mm, 1));
        CHECK(wn::contains_key(mm, 2));

        int v = 0;
        bool found = false;

        found = wn::get_key(mm, 1, v, 10);
        CHECK(found);
        CHECK_EQ(v, 1);

        found = wn::get_key(mm, 10, v, 10);
        CHECK(!found);
        CHECK_EQ(v, 10);
    }

    // set:
    {
        std::set<std::string> s{"one", "two"};

        CHECK(wn::contains(s, std::string("one")));
        CHECK_EQ(wn::contains(s, std::string("three")), false);
    }

    // split
    {
        wn::split_with_callback("1,2,,3", ",", [](size_t i, const char* token){
            LOG(INFO) << " i: " << i << " token: '" << token << "'";
        });
    }
    
    LOG(INFO) << "it works!";

    return EXIT_SUCCESS;
}
