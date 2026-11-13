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
