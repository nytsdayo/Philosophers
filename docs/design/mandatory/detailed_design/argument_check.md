# int ph_argument_check(t_arg const argument)
## 処理
- 引数の数チェック(`argc_check`)
- 引数が数値であるか(`argv_num_check`)
- 引数が適切な数値であるか(`argv_validate_num_check`)
	- 0 < input < 256。
## 返り値
- 0:SUCCESS
- 引数が適切でない値の場合、下記を返す。
	- `ERROR_INVALID_ARGC`
	- `ERROR_INVALID_ARGV_NOT_NUM`
	- `ERROR_INVALID_ARGV_PARAM`
