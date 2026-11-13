# Swerve

```bash
docker build -t ros-swerve-env .
```

```bash
docker run --rm -it --name swerve-container -v "$(pwd):/swerve" ros-swerve-env
```

```bash
docker exec -it swerve-container bash
```

```bash
# 1. 準備 ~/.ssh 目錄
mkdir -p ~/.ssh && chmod 700 ~/.ssh

# 2. 產生金鑰（建議設 passphrase）
ssh-keygen -t ed25519 -C "srecruit" -f ~/.ssh/work
chmod 600 ~/.ssh/work
chmod 644 ~/.ssh/work.pub

# 3. 寫入 config
cat >> ~/.ssh/config <<'EOF'
Host srecruit.csie.ncku.edu.tw
    User git
    IdentityFile ~/.ssh/work
    IdentitiesOnly yes
EOF
chmod 600 ~/.ssh/config

# 4. 印出公鑰，貼到網站的 SSH Keys 設定頁
cat ~/.ssh/work.pub

# 5.（如果有設 passphrase）加進 agent，就不用每次輸入
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/work

# 6. 測試連線（第一次會問 host key，確認後輸入 yes）
ssh -T srecruit.csie.ncku.edu.tw

# 7. 使用
git clone git@srecruit.csie.ncku.edu.tw:<帳號>/<repo>.git
# 或對既有 repo 設定 remote：
git remote add origin git@srecruit.csie.ncku.edu.tw:<帳號>/<repo>.git
git push -u origin main
```

```bash
./swerve_robot
```

```bash
make clean
```
# 參考資料

## 記憶體順序 / SPSC 無鎖佇列
- [memory_order 權威定義](https://docs.cs.uct.ac.za/cpp/reference/en/cpp/atomic/memory_order.html)
- [memory_order 中文版](https://zh.cppreference.com/w/cpp/atomic/memory_order)
- [無鎖佇列 push/pop 完整實作](https://www.zhihu.com/tardis/jm/ans/2047784907330605455)
- [用原子操作實作無鎖佇列](https://jishuzhan.net/article/2002537644396445698)
- [SPSC ring buffer：免 CAS、acquire/release、防 false sharing](https://0xkiire.pages.dev/lock-free-spsc-ring-buffer)
- [無鎖佇列教學](https://awesome-embedded-learning-studio.github.io/Tutorial_AwesomeModernCPP/en/vol5-concurrency/ch04-concurrent-data-structures/04-lock-free-queues)

## ROS 2 Executor
- [單/多執行緒 executor 與回調組](https://ros-x.github.io/docs/tutorials/executor)
- [executor 官方概念](https://docs.ros.org/en/lyrical/Concepts/Intermediate/About-Executors.html)
- [callback group 官方用法](https://docs.ros.org/en/lyrical/How-To-Guides/Using-callback-groups.html)
- [executor 文章](https://blog.csdn.net/breaksoftware/article/details/140803966)
- [SingleThreadedExecutor API](https://api.nav2.org/jazzy/html/classrclcpp_1_1executors_1_1SingleThreadedExecutor.html)

## ROS 2 QoS
- [QoS 通訊策略選擇](https://damodev.csdn.net/696f9ace7c1d88441d8e4f01.html)
- [ROS 2 總複習](https://damodev.csdn.net/696b8399a16c6648a9830d21.html)
- [QoS 官方 demo](https://docs.ros.org/en/lyrical/Tutorials/Demos/Quality-of-Service.html)

## ROS 2 參數
- [C++ 節點參數：declare_parameter、回呼、ros2 param](https://www.cnblogs.com/ljbguanli/p/19301138)
- [參數使用教學](https://foxglove.dev/blog/how-to-use-ros2-parameters)
- [在 C++ class 中使用參數](https://docs.ros.org/en/ros2_documentation/galactic/Tutorials/Beginner-Client-Libraries/Using-Parameters-In-A-Class-CPP.html)

## PIO
- [RP2350 datasheet（PIO 章節）](https://datasheets.raspberrypi.com/rp2350/rp2350-datasheet.pdf)
- [PIO 入門](https://docs.micropython.org/en/latest/rp2/tutorial/pio.html)
- [MicroPython PIO 函式](https://waveshare.com/wiki/%E3%80%90MicroPython%E3%80%91PIO_Function)
- [PIO 指令集、ISR/OSR](https://ryanjtr.github.io/MyDocs/Contents/Raspberry/programableIO.html)
- [PIO 概念介紹](https://magazine.raspberrypi.com/articles/what-is-programmable-i-o-on-raspberry-pi-pico)
- [MicroPython PIO 教學](https://www.digikey.com/es/maker/projects/raspberry-pi-pico-and-rp2040-micropython-part-3-pio/3079f9f9522743d09bb65997642e0831)
- [PIO 常見陷阱](https://towardsdatascience.com/nine-pico-pio-wats-with-micropython-part-1-82b80fb84473/)

## ThreadSanitizer
- [用 TSan 檢查資料競爭](https://wizardforcel.gitbooks.io/100-gcc-tips/content/thread-sanitizer.html)
- [TSan 文章](https://bbs.huaweicloud.com/blogs/463379)
- [死鎖、資料競爭、原子性違反](https://cnblogs.com/papering/p/16748576.html)


