## Usage
create output directory `mkdir out` then,

create store directory`mkdir db`

build `./build.sh`

execute `./out/unko.exe`

## できること
- テーブル作成 [Create]
- テーブル削除 [Delete]
- テーブルを編集 [Edit]
- テーブル一覧を見る [Show]

### テーブル作成
データベースを作成する

データベースの名前を入力。列名とデータの種類(Int, Double, Stringのどれか)を入力する

これで、自分の思うがままのデータベースを作ることができる。

### テーブル削除
入力した名前のデータベースのデータを削除する

### テーブル編集
- テーブルの行追加 [insert]
- テーブルの行削除 [delete]
- テーブルの中身を表示する [show]

### テーブル一覧を見る
存在するデータベースを全て表示する(内容が表示されるわけではない)
