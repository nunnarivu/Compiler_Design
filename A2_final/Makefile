

CXXFLAGS = -I/usr/lib/llvm-9/include -fPIC -fvisibility-inlines-hidden -pedantic -std=c++11 -ffunction-sections -fdata-sections -O2 -g -DNDEBUG  -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS


cc: asttree.cpp cc.cpp c.tab.cpp c.lex.cpp
	@clang++ asttree.cpp c.tab.cpp c.lex.cpp cc.cpp -lm -ll -lfl $(CXXFLAGS) `llvm-config --ldflags --system-libs --libs all` -o $@
c.tab.cpp c.tab.hpp: c.y
	bison -o c.tab.cpp -d c.y

c.lex.cpp: c.l c.tab.hpp
	flex -o c.lex.cpp -l c.l

clean::
	rm -f c.tab.cpp c.tab.hpp c.lex.cpp cc c.output
