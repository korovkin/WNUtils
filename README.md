# WNUtils
useful C++ functions (zero dependencies)

## compile
```
mkdir -p _build && cd _build && cmake ../ && make && ./wnutils && cd ..
```

## example:
```c++
#include "WNUtils.h"

{
  std::map<int, int> mm{
      {1, 1},
  };
  
  // contains:
  CHECK(wn::contains_key(mm, 1));

  int v = 0;
  bool found = false;

  // get or default:
  found = wn::get_key(mm, 1, v, 10);
  CHECK(found);
  CHECK_EQ(v, 1);
  
  // get or default:
  found = wn::get_key(mm, 10, v, 10);
  CHECK(!found);
  CHECK_EQ(v, 10);
}

```

