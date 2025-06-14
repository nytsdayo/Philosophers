# philo_action.md

## philo_action
- `void *ph_philo_act(void *arg)`
### description
- 下記の処理で順番を行う
	- `ph_philo_thinking(t_philo_data philo_data)`
	- `ph_philo_eating(t_philo_data philo_data)`
	- `ph_philo_sleeping(t_philo_data philo_data)`
### return value
- THINK_FINISH: Indicates that the philosopher has finished thinking.
- EAT_FINISH: Indicates that the philosopher has finished eating.
- SLEEP_FINISH: Indicates that the philosopher has finished sleeping.
- CLOSE_DINING: Indicates that the dining session has been closed.
- PHILO_DEAD: Indicates that the philosopher has died during one of the actions.

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

## その他必要な関数

### ph_philo_pick_forks
`ph_philo_pick_forks(t_philo_data philo_data)`
#### description
- 哲学者が両隣のフォークを取得する処理を行う。
- フォークの取得に失敗した場合は待機またはリトライを行う。
#### return value
- SUCCESS: フォークの取得に成功した場合
- PHILO_DEAD: 待機中に死亡した場合

### ph_philo_release_forks
`ph_philo_release_forks(t_philo_data philo_data)`
#### description
- 哲学者が使用したフォークを解放し、他の哲学者が利用できるようにする。
#### return value
- SUCCESS

### ph_philo_check_death
`ph_philo_check_death(t_philo_data philo_data)`
#### description
- 哲学者が死亡しているかどうかを判定する。
#### return value
- PHILO_DEAD: 死亡している場合
- ALIVE: 生存している場合

### ph_philo_update_last_meal
`ph_philo_update_last_meal(t_philo_data philo_data)`
#### description
- 最終食事時刻を更新する。
#### return value
- SUCCESS

### ph_philo_log_action
`ph_philo_log_action(t_philo_data philo_data, philo_action action)`
#### description
- 哲学者の行動をログに記録する。
#### return value
- SUCCESS