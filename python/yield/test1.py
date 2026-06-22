#!python3

class  YieldTester

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

# End Class (YieldTest)

counter = 0
tester = YieldTest()
for i in range(10):
    r = tester.test(i)
    counter += 1
    print("MAIN : {counter=}, {r=}")
# Next (i)
