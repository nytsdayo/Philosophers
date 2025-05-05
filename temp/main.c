#include <stdio.h>
#include <sys/time.h> // gettimeofday関数を使用するために必要

/*
- gettimeofday関数を用いた、処理回数と処理時間の対応の目安を出力する関数
*/
int main() {
    struct timeval start_time, current_time;
    long sec_diff, usec_diff;
    double elapsed_ms; // 経過時間をミリ秒(ms)で格納する変数

    // 1. プログラム開始時刻を取得
    gettimeofday(&start_time, NULL);
    printf("program start\n");

    int i = 0;
	int j;
    const int max_loop = 1000000; // ループの最大回数
	int per_loop = 10;
    const int report_interval = 100000; // 報告する間隔

    printf("1ループあたり%d回処理を開始します (最大 %d 回)...\n",per_loop ,max_loop);

    // 2. whileループを開始 (1,000,000回)
    while (i < max_loop) {
		j = per_loop;
		while(j > 0)
			j--;
        // 3. 1000回ごとに経過時間を出力
        if (i % report_interval == 0) {
            // 現在時刻を取得
            gettimeofday(&current_time, NULL);

            // 経過時間を計算 (秒とマイクロ秒で)
            sec_diff = current_time.tv_sec - start_time.tv_sec;
            usec_diff = current_time.tv_usec - start_time.tv_usec;

            // マイクロ秒の差が負の場合、秒から繰り下げ
            if (usec_diff < 0) {
                sec_diff--;
                usec_diff += 1000000; // 1秒 = 1,000,000マイクロ秒
            }

            // ★変更点: 経過時間をミリ秒(ms)に変換
            // (秒 * 1000) + (マイクロ秒 / 1000)
            elapsed_ms = (double)sec_diff * 1000.0 + (double)usec_diff / 1000.0;

            // ★変更点: 結果をミリ秒で出力 (小数点以下3桁まで表示)
            printf("ループ %7d 回時点: %.3f ms\n", i, elapsed_ms);
        }

        // --- ループ内で行う本来の処理 ---
        // (省略)
        // volatile int dummy = i * i;
        // --- ここまで ---

        i++; // ループカウンタをインクリメント
    }

    // 4. ループ終了後、最終的な経過時間をミリ秒で出力
    gettimeofday(&current_time, NULL);
    sec_diff = current_time.tv_sec - start_time.tv_sec;
    usec_diff = current_time.tv_usec - start_time.tv_usec;
    if (usec_diff < 0) {
        sec_diff--;
        usec_diff += 1000000;
    }
    // ★変更点: 経過時間をミリ秒(ms)に変換
    elapsed_ms = (double)sec_diff * 1000.0 + (double)usec_diff / 1000.0;

    // ★変更点: 結果をミリ秒で出力
    printf("ループ %7d 回終了時点: %.3f ms\n", i, elapsed_ms);
    printf("プログラムを終了します。\n");

    return 0;
}