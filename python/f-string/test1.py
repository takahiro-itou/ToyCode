#!/usr/bin/env  python3

hoge = 123

inputs = 'hoge は {hoge} です'
print(inputs)

f_inputs="f'{inputs}'".format(inputs = inputs,)
print(f_inputs)

text = eval(f_inputs)
print(text)
