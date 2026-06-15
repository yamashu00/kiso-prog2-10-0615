# 基礎プログラミングII — 第10回 演習

**日付:** 2026-06-15　**テーマ:** テキストファイルを行単位で読む + サイエンスアート

---

## 前回（#9）から今回（#10）へのつながり

前回は「ファイルにデータを書いて、読み直す」基本を学びました。

```
前回（#9）でできるようになったこと
  fopen / fprintf / fscanf / fclose
  → ファイルに数字や単語を書いて、読み直せる

でも、こんな行が読めなかった
  "夕焼け オレンジ,30,90,95,400,300,80"
          ↑
      スペースが入っている！
      fscanf はスペースで読み取りを止めてしまう
```

```
今回（#10）で解決する
  fgets  → 1行まるごと読む（スペースも日本語もOK）
  sscanf → 読んだ行をフィールドごとに分解する
```

---

## これができるようになると何が変わるか

| やりたいこと | 今回学ぶ技術 |
|------------|------------|
| スペースや日本語を含む CSV を読む | `fgets` + `sscanf` |
| 色のデータを読んで画面に描く | `fgets` + `sscanf` + `raylib` |
| センサーのログを全行まとめて処理する | `fgets` ループ |
| 「プログラムとデータを分ける」設計をする | CSV ファイルを差し替えるだけで動作が変わる |

**今回の最終ゴール：**  
`color.csv` の中身（色・座標・サイズ）を書き換えるだけで、  
画面に表示される絵がそのまま変わるプログラムを作る。

---

## ファイル構成（この順番に進めてください）

| 順番 | ファイル | 内容 |
|:---:|---------|------|
| 0 | `step0_debug_quiz.c` | 【復習】前回のバグ探し（fopen / NULLチェック / fclose） |
| 1 | `step1_fgets_line.c` | fgets で1行だけ読む |
| 2 | `step2_fgets_loop.c` | fgets ループで全行読む |
| 3 | `step3_sscanf_parse.c` | sscanf で文字列を分解する |
| 4 | `step4_color_csv.c` | color.csv を読んでテキスト表示（完成版） |
| 5 | `step5_color_draw.c` | color.csv を読んで raylib で描画（完成版） |
| ★ | `bonus_odd_divisible.c` | ボーナス問題（数学 × プログラム） |

---

## コマンド一覧（VS Code ターミナルで使う）

### ターミナルを開く
```
Ctrl + `（バッククォート）
```

### ファイルを確認する

```bash
ls                        # 今いるフォルダのファイル一覧を表示
cat color.csv             # ファイルの中身をそのまま表示
```

### コンパイルして実行する

```bash
# 基本の形: gcc ソースファイル名 -o 実行ファイル名
gcc step1_fgets_line.c -o step1
./step1

gcc step2_fgets_loop.c -o step2
./step2

gcc step3_sscanf_parse.c -o step3
./step3

gcc step4_color_csv.c -o step4
./step4

# step5 は raylib が必要（-lraylib -lm をつける）
gcc step5_color_draw.c -o step5 -lraylib -lm
./step5

# bonus
gcc bonus_odd_divisible.c -o bonus
./bonus
```

### よく使うその他のコマンド

```bash
# ファイルをコピーする
cp color.csv color_backup.csv

# ファイルを削除する（注意：元に戻せない）
rm step1

# 直前のコマンドをもう一度実行する（↑キーで履歴をたどれる）
↑ キー

# コンパイル → 実行を1行でやる（&& は「前が成功したら次を実行」）
gcc step4_color_csv.c -o step4 && ./step4
```

### エラーが出たとき

```bash
# エラーメッセージの例
step4_color_csv.c:12:5: error: ...
     ↑            ↑
  ファイル名    行番号   ← VS Code でその行にジャンプして確認する
```


### Homebrew インストール（未導入の場合）
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# raylib インストール
brew install raylib

# コンパイル
gcc main.c -o main -lraylib -framework OpenGL -framework Cocoa -framework IOKit
```
---

## ★ おすすめ外部コンテスト

今回学ぶ「データをファイルで扱う」「プログラムで問題を解く」技術は、  
コンテストでそのまま使えます。ぜひ挑戦してみてください！

---

### 四国リーディングエッジ
**https://www.leadingedge-shikoku.com/**

| 項目 | 内容 |
|------|------|
| 対象 | 四国・瀬戸内圏域にゆかりのある 15〜25歳未満（高専生OK） |
| テーマ | IT・デジタル技術を使ったアイデアなら自由 |
| 支援 | 最大 **75万円** の開発支援金 ＋ 専門家メンタリング |
| 採択数 | 最大10組 |
| ⚡ アーリーエントリー | **6月30日（月）締め切り** ← 早めに出すと有利 |
| レギュラーエントリー | 8月10日（月）17:00 |

---

### re-KOSEN（中四国の高専生対象）
**https://re-kosen.com/**

| 項目 | 内容 |
|------|------|
| 対象 | 中四国地域の高専生（学年不問、1〜4名、複数校チームも可） |
| テーマ | ① 自由コース（自分の興味を深堀り） ② 課題コース（ITで地域課題を解決） |
| 支援 | 活動支援金 ＋ 専門メンターが **6ヶ月間** 伴走 |
| 主催 | 経済産業省 AKATSUKIプロジェクト採択事業 |
| ⚡ 応募締め切り | **7月6日（月）23:59** |

---

## Pull Request の送り方

```bash
# 1. Fork したリポジトリをクローン
git clone https://github.com/あなたのID/kiso-prog2-10-0615.git
cd kiso-prog2-10-0615

# 2. 自分の名前でブランチを作る
git checkout -b yamada-taro

# 3. ファイルを編集・追加したら
git add .
git commit -m "yamada-taro: 第10回提出"
git push origin yamada-taro

# 4. GitHub で Pull Request を作成する
```
