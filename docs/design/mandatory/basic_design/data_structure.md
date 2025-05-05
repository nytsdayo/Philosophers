## 実行単位
- philosopherの人数分、哲学者の実行単位がある。
### 給仕係
- all_philo_state
- all_philo_eat_count
### 哲学者
- philo_info
	- time_to_die
	- time_to_sleep
	- time_to_eat
	- must_eat_count  (option)
		- if not set, param=0
- philo_state (共有資源 `各哲学者の状態`)
	- `THINK`,`EAT`,`SLEEP`
	- 書き込み
- is_alive(共有資源`各哲学者の生存状態`)
	- 書き込み
- last_eat_time
	- init:0
- eat_count
	- init:0
- seat_no
- dining_state(ptr)
	- 参照
- left_fork(ptr) -> seat_number番目のフォークのアドレス
- right_fork(ptr) -> seat_number+1番目のフォーク(`seat_number=哲学者の人数`の時、1番目のフォーク)のアドレス
### 監視者
- 各哲学者の生存状態(共有資源)
	- 参照
- 食事会の開催状態(共有資源)
	- 書き込み

## 共有資源
- 各資源について、ミューテックスで保護をする。
### 食事会の開催状態
- state structure
	- is_open : true/false
	- mutex_dining_state
### フォーク
- 個数：哲学者の人数分
- fork_strucure
	- enable_use : true/false
	- mutex_enable_request
	- フォークそのものをmutexで保護(mutex_fork)
### 各哲学者の状態
- philo_state
	- philo_state : think/eat/sleep
	- mutex_philo_state
### 各哲学者の生存状態
- philo_alive_state
	- philo_alive_state : alive/dead
	- mutex_philo_alive_state
### 出力用
- print_mutex

