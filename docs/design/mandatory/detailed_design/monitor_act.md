# monitor_act.md

## monitor_act
`void *monitor_act(void *monitor_param)`
### descprition
- 下記の手順に従って処理を行う。
	- 以下の条件になるまで、各哲学者の生存状態について確認を行う
		- いずれかの哲学者が死亡する。
	- 上記条件を満たすと、dining_stateをcloseにする。

### return value（要深堀）
成功ステータス
エラーステータス
