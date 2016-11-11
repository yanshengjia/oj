// Created by sjyan @2016-11-11

class Solution {
public:
  int addDigits(int num) {
    while (1) {
      if (num / 10 == 0)
        return num;

      int t = 0;

      while (1) {
        t += num % 10;
        num /= 10;

        if (num / 10 == 0) {
          t += num;
          num = t;
          break;
        }
      }
    }
  }
};
