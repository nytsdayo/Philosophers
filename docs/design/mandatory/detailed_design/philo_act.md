# philo_action.md

## philo_action
- `void *ph_philo_act(void *arg)`
### description
- 下記の処理で順番を行う
	- `ph_philo_thinking(t_philo_data philo_data)`
	- `ph_philo_eating(t_philo_data philo_data)`
	- `ph_philo_sleeping(t_philo_data philo_data)`
### return value
// 要定義

---
## ph_philo_thinking
`ph_philo_thinking(t_philo_data philo_data)`
### description
- 下記状態になるまで待機をする。
	- philo_stateがeatになる。
	- dining_stateがcloseになる。
	- phil_alive_stateがdeadになる。
### return value
THINK_FINISH
CLOSE_DINING
PHILO_DEAD

## ph_philo_eating
`ph_philo_eating(t_philo_data philo_data)`
### description
- 下記の順番で処理を行う
	- 両隣のフォークを取る
	- 規定時間食事をする
		- 食事中に一定時間を超えると死亡する。
	- 両隣のフォークを解放し、フォークを利用可能状態にする。
	- 最終食事時刻の更新
### return value
EAT_FINISH
CLOSE_DINING
PHILO_DEAD

## ph_philo_sleeping
`ph_philo_sleeping(t_philo_data philo_data)`
### description
- 下記の順番で処理を行う
	- 規定時間睡眠をする
		- 睡眠中に一定時間を超えると死亡する。
### return value
- SLEEP_FINISH
- CLOSE_DINING
- PHILO_DEAD
