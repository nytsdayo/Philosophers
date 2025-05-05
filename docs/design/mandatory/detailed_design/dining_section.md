# dining_section
## parent_function
`int	ph_dining_section(int argc,char **argv)`
### description
- 下記の順番で処理を行う。
	- ph_init_dining
		- 食事会に関する構造体のポインタを取得する。
		- NULLポインタが帰ってきた時、初期化に失敗しているため`INIT_FAILED`を返す。
	- ph_run_dining
		- 食事会の実行を行う。
	- ph_exit_dining
		- 食事会に関する構造体を解放する。
### return
- 食事会が開催されたかどうかを返す。
- 0 : SUCCESS_DINING(食事会が開催された時)
- 1 : INIT_FAILED(食事会の初期設定が失敗した時)

---

## ph_init_dining
`t_philos_dining_env	*ph_init_dining(int argc,char **argv)`
### description
- 下記の順番で処理を行う
	- argvの各値を数値に変換し、5要素の数値配列に格納。
		- `argc=5`の場合、must_eat_countに値する要素は`0`とする。
	- ph_get_philo_info
		- 5要素の数値配列の値を元に、哲学者の情報が格納された構造体を取得。
	- ph_init_share_resource
		- 共有資源のミューテックスを設定する。
		- ミューテックスの設定に失敗した時、NULLポインタを返す(要調査)
	- ph_init_philosopher
		- 5要素の数値配列の`number_of_philosopher`に対応する数だけ、哲学者を構成する構造体を生成する。
		- メモリ確保に失敗した場合、NULLポインタを返す。
	- ph_init_monitor
		- philosopher全員の`is_alive`のポインタを格納した、監視者を構成する構造体を生成する。
		- メモリ確保に失敗した場合、NULLポインタを返す。
	
## ph_run_dining
`int	ph_run_dining(t_philos_dining_env *dining_env)`
### description
- 下記の順番で処理を行う
	- `pthread_create(&monitor_thread,NULL,&routine,&monitor_data)`
	- `pthread_detach(monitor_thread)`
	- `pthread_create(&philo_thread,NULL,&philo_act,&philo_data)`
		- 生成と同時に、スレッドが動き出す。
		- モニタは生成と同時にデタッチする。
	- 各スレッドでroutine(哲学者の食事行動)を実行する。
	- `pthread_join(philo_thread)`
		- 哲学者全員の食事が終わるのを待つ。

## ph_exit_dining
`int	ph_exit_dining(t_philos_dining_env *dining_env)`
- dining_env内の共有資源を解放する
- dining_env内の動的に割り当てた資源を解放する

## ph_philo_act
`void	*ph_philo_act(void *arg)`
- 哲学者の食事行動
