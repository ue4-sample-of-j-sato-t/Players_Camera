# Players_Camera
https://docs.unrealengine.com/ja/Programming/Tutorials/PlayerCamera/index.html

## メモ

- 入力系をコントローラに移して実装する

## プレイヤーコントローラーでの入力バインド

- `SetupInputComponent`をオーバーライド
- フィールド`InputComponent`を使ってバインドを行う
	- `BindAxis`や`BindAction`を使う

## うまく動いていない

- 回転がアクタごとなのでActorForwardVectorが下向きになる
	- 全身し続けると床を抜けてしまう
	- ピッチの回転をアクタ全体でなく表示物だけにする？