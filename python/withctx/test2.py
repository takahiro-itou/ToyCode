#!/bin/python3

class CtxDemo:

    def __init__(self, value):
        print("CtxDemo##__init__ : value = {0}".format(value,))
        self._value = value

    def __enter__(self):
        print('CtxDemo##__enter__')
        return  self

    def __exit__(self, *args):
        print("CtxDemo##__exit__ : args = {0}".format(args,))

    def print_value(self):
        print("CtxDemo##print_value : {0}".format(self._value,))

# End Class (CtxDemo)


class  WrapCtx:

    def __init__(self, value):
        print("WrapCtx##__init__ : value = {0}".format(value,))
        self._target = CtxDemo(value)

    def __enter__(self):
        print('WrapCtx##__enter__')
        return  self._target.__enter__()

    def __exit__(self, *args):
        print("WrapCtx##__exit__ : args = {0}".format(args,))
        self._target.__exit__(*args)

# End Class (WrapCtx)


with WrapCtx(123) as ctx:
    ctx.print_value()
