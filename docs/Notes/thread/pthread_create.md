## pthread_create
```
<pthread.h>
int pthread_create(pthread_t *restrict thread,
                   const pthread_attr_t *restrict attr,
                   void *(*start_routine)(void *),
                   void *restrict arg);
```
- `pthread_t *thread`
	- 役割: 新しく生成されるスレッドの識別子（スレッドID）を格納するためのポインタです。
	- 詳細: 関数が成功すると、このポインタが指す pthread_t 型の変数に、OSが割り当てた一意のスレッドIDが格納されます。このIDは、後で pthread_join や pthread_detach などでスレッドを操作する際に使用します。
- `const pthread_attr_t *attr`
	- 役割: 新しいスレッドの属性を指定するためのポインタです。
	- 詳細: スレッドの属性（スタックサイズ、デタッチ状態、スケジューリングポリシーなど）をカスタマイズしたい場合に、pthread_attr_init などで初期化・設定した pthread_attr_t オブジェクトへのポインタを渡します。デフォルトの属性で良い場合は NULL を指定します。
- `void *(*start_routine)(void *)`
	- 役割: 新しいスレッドが実行を開始する関数（スレッド関数）へのポインタです。
	- 詳細: この関数は void * 型の引数を1つ受け取り、void * 型の値を返すシグネチャを持つ必要があります。新しいスレッドはこの関数を実行します。
- `void *arg`
	- 役割: start_routine として指定した関数に渡される引数です。
	- 詳細: スレッド関数に必要なデータを渡すために使用します。通常、複数のデータを渡したい場合は、構造体へのポインタを void * 型にキャストして渡します。スレッド関数側では、受け取った void * 型の引数を元の型（構造体へのポインタなど）にキャストし直して使用します。引数が必要ない場合は NULL を指定できます。
### RETURN VALUE
- 成功時: 0 を返します。
- 失敗時: エラーを示す正のエラー番号（errno とは異なります）を返します。主なエラーコードには以下のようなものがあります。
	- EAGAIN: 新しいスレッドを作成するためのリソースが不足している（例: プロセスあたりのスレッド数上限に達した）。
	- EINVAL: attr で指定された属性が無効。
	- EPERM: attr で指定されたスケジューリングポリシーやパラメータを設定する権限がない。