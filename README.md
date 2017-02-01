# WNUtils
useful C++ functions (zero dependencies)

## compile
```
mkdir -p _build && cd _build && cmake ../ && make && ./wnutils && cd ..
```

## example:
```c++
{
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
      wn::split_with_callback("1,2,3,4", ",", [](size_t i, const char* token){
          CHECK_EQ(std::to_string(i+1), std::string(token));
      });

      std::vector<std::string> vStrings;
      wn::split("1,2,,3", ",", vStrings);
      CHECK_EQ(vStrings[0], "1");
      CHECK_EQ(vStrings[1], "2");
      CHECK_EQ(vStrings[2], "");
      CHECK_EQ(vStrings[3], "3");
  }

  // join:
  {
      std::vector<int> vInts = {1,2};
      CHECK_EQ(wn::join(vInts, ","), "1,2");
      CHECK_EQ(wn::join(vInts, ", "), "1, 2");

      std::map<int, int> mInts = {
          {1, 1},
          {2, 2},
      };
      CHECK_EQ(wn::join(mInts, ","), std::string("(1,1),(2,2)"));

      std::map<std::string, std::string> mStrings = {
          {"x", "xx"},
          {"y", "yy"},
      };
      CHECK_EQ(wn::join(mStrings, ","), std::string("(x,xx),(y,yy)"));
  }
}
```

