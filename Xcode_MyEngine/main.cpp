#include "MyEngine.h"
#include <cstdlib> // 用于 rand()
#include <ctime>   // 用于 srand()

int main(void) {
    InitWindow(640, 480, "Hello");
    InitEngineTime(); // 初始化计数器
    
    srand((unsigned int)time(NULL)); // 初始化随机种子
    
    while (GameShouldQuit()) {
        UpdateDeltaTime(); // 更新帧时间
        std::cout << (float)GetDeltaTime() << std::endl;
        // START 测试
        // 打印当前的 DeltaTime 和 FPS (1/dt)
                float dt = GetDeltaTime();
                if (dt > 0) {
                    std::cout << "DT: " << dt << " s | FPS: " << (int)(1.0f / dt) << std::endl;
                }

                // 2. 逻辑处理：清屏（每一帧都清空，否则会堆积成色块）
        ClearScreen();

                // 3. 渲染：每一帧画 100 条随机线条
                for (int i = 0; i < 100; i++) {
                    // 生成随机坐标
                    int x1 = rand() % 640;
                    int y1 = rand() % 480;
                    int x2 = rand() % 640;
                    int y2 = rand() % 480;

                    // 生成随机颜色
                    Color randomColor = {
                        (uint8_t)(rand() % 256), // R
                        (uint8_t)(rand() % 256), // G
                        (uint8_t)(rand() % 256), // B
                        255                      // A (不透明)
                    };

                    // 调用你的 Bresenham 画线函数
                    DrawLine(x1, y1, x2, y2, randomColor);
                }
        // END
        Rend();
    }
    CleanUp();
    return 0;
}
