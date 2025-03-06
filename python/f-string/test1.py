#!/usr/bin/env  python3

hoge = 123

# inputs に指定したテキストのうち {} で括られた部分は変数として置換を行う
inputs = 'hoge は {hoge} です'
print(inputs)

f_inputs="f'{inputs}'".format(inputs = inputs,)
print(f_inputs)

text = eval(f_inputs)
print(text)

# 変数名 (fuga) が定義されていない時の挙動テスト
# エラーになる予定
inputs = 'fuga は {fuga} です'
print(inputs)

f_inputs="f'{inputs}'".format(inputs = inputs,)
print(f_inputs)

text = eval(f_inputs)
print(text)
