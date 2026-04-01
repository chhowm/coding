#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0;
    const char* words[4] = {"aya", "ye", "woo", "ma"};
    int lengths[4] = {3, 2, 3, 2};

    for (int i = 0; i < babbling_len; i++) {
        int pos = 0; // 현재 검사 중인 문자열 내 위치
        int len = strlen(babbling[i]);

        while (pos < len) {
            bool matched = false;

            for (int j = 0; j < 4; j++) {
                // 현재 위치(pos)부터 단어가 일치하는지 확인
                if (strncmp(&babbling[i][pos], words[j], lengths[j]) == 0) {
                    pos += lengths[j]; // 일치하면 그 단어 길이만큼 포인터 이동
                    matched = true;
                    break;
                }
            }

            // 네 단어 중 아무것도 매칭되지 않으면 이 단어는 실패
            if (!matched) break;
        }

        // 끝까지 깔끔하게 읽었다면 조카가 발음할 수 있는 단어!
        if (pos == len) {
            answer++;
        }
    }

    return answer;
}