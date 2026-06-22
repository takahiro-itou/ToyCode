#!python3

class  YieldTester:

    def __init__(self):
        self._packs = []
        self._num_yields = 0
        pass

    def test(self, val):
        print(f"CALL test {val=}")
        self._packs.append(val)
        if len(self._packs) >= 3:
            self._num_yields += 1
            print(f"yield {self._packs=}, {self._num_yields=}")
            yield  self._packs
            self._packs = []
        # End If
    # End Def (test)

# End Class (YieldTester)


class  MyIterator:

    def __init__(self, it):
        self._it = it
        self._tester = YieldTester()

    def __iter__(self):
        return  self

    def __next__(self):
        yield from  self._tester(next(self._it))

# End Class (MyIterator)


counter = 0
myit = MyIterator(range(10))

for x in myit:
    counter += 1
    print(f"MAIN : {counter=}, {x=}")
# Next (i)
