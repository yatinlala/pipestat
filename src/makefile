##########################################################################
#                            MAKEFILE
#=========================================================================
#	This is the makefile for |STAT data analysis programs.
#	There are macros at the beginning of this file.  Mostly they
#	help you customize.  The # comment character is placed
#	immediately after the value to avoid unwanted spaces.
##########################################################################
#                            WARNINGS
#=========================================================================
# With my version of gcc,
#      the -O option caused incorrect results with anova.
#      you may need to compile with the -bsd option added to CFLAGS
##########################################################################

DESTDIR=../../bin#                            destination directory
DESTDIR=../bin#                               destination directory
CFLAGS =-O#                                   C Compiler Options - add -Wall for all warnings
CFLAGS += -Wno-implicit-function-declaration
LINK   =$(CC) $(CFLAGS) -o $(DESTDIR)/$@#     Generic link command
LIBS   =-lm#                                  libraries needed (math)
EDITOR =/usr/ucb/vi#                          editor to call on make edit
RM     =/bin/rm -f#                           remove forcefully
MV     =/bin/mv#                              move/rename files
YACC   =/bin/yacc#                            compiler compiler
YACC   =/usr/bin/bison#                       gnu yacc compiler compiler
MAKE   =/bin/make#                            use for recursive makes
MAKE   =/usr/bin/make#                        use for recursive makes
GETOPT =getopt.o#                             use this if you get complaints about getopt being undefined
GETOPT =#                                     use this if you get complaints about getopt being redefined

MAINS = abut.c anova.c calc.y colex.c contab.c desc.c dm.y dprime.c \
	dsort.c features.c ff.c fpack.c linex.c maketrix.c oneway.c \
	pair.c perm.c probdist.c rankind.c rankrel.c ranksort.c \
	regress.c repeat.c reverse.c series.c stats.c transpose.c \
	ts.c validata.c

PROGS = abut anova calc colex contab desc dm dprime \
	dsort features ff fpack linex maketrix oneway \
	pair perm probdist rankind rankrel ranksort \
	regress repeat reverse series stats transpose \
	ts validata
# add cat to the above list if you do not have one on your system

UTILS = barplot.c centile.c chisq.c chitest.c cistrcmp.c confirm.c cor.c \
	f.c fisher.c fiveplot.c getopt.c getword.c mdmat.c \
	number.c numcmp.c numline.c ordstat.c \
	parseline.c primes.c prodlist.c random.c readlines.c setint.c setreal.c \
	skipnumber.c specol.c strings.c tmpfile.c z.c

all:
	@/bin/echo "Making all the |STAT Programs"
	@/bin/echo "Using compiler=$(CC) with options=$(CFLAGS)"
	@/bin/echo "Installing in directory=$(DESTDIR)"
	@$(MAKE) -i $(PROGS)

test:
	@/bin/echo "Testing the |STAT Programs"
	@PATH=${DESTDIR}:$PATH cd ../example; chmod +x example; example | diff ../example/example.out - && /bin/echo "Test of programs in ${DESTDIR} in example directory passed"

edit:
	@$(EDITOR) $(MAINS)

clean:
	@-$(RM) *.o y.tab.* core a.out *.P *.X *mon.out cscope.out $(PROGS)

archive: makefile $(UTILS) $(MAINS)
	archive
	touch archive

.PRECIOUS: makefile $(UTILS) $(MAINS)


ABUT=abut.o number.o ${GETOPT} setint.o
abut: $(ABUT)
	$(LINK) $(ABUT)

ANOVA=anova.o parseline.o number.o f.o tmpfile.o ${GETOPT} numcmp.o errplot.o numline.o setint.o
anova: $(ANOVA)
	$(LINK) $(ANOVA) $(LIBS)

CALC=calc.o skipnumber.o
calc: $(CALC)
	$(LINK) $(CALC) $(LIBS)
calc.c: calc.y
	${YACC} calc.y
	$(MV) y.tab.c calc.c

cat:
	$(LINK) -DCAT filter.c

COLEX=colex.o parseline.o number.o ${GETOPT} specol.o
colex: $(COLEX)
	$(LINK) $(COLEX)

CONTAB=contab.o number.o tmpfile.o parseline.o ${GETOPT} chisq.o z.o \
	fisher.o prodlist.o primes.o numcmp.o setint.o
contab: $(CONTAB)
	$(CC) $(CFLAGS) -DI_DATA -c mdmat.c
	$(LINK) $(CONTAB) mdmat.o $(LIBS)
contab.o:
	$(CC) $(CFLAGS) -DI_DATA -c contab.c

DESC=desc.o ${GETOPT} f.o setreal.o number.o getword.o centile.o
desc: $(DESC)
	$(LINK) $(DESC) $(LIBS)

DM=dm.o strings.o number.o random.o confirm.o skipnumber.o
dm: $(DM)
	$(LINK) $(DM) $(LIBS)
# if dm is compiled without the -DPTREE option, then there will be
# no facility for printing the parsings of expressions and dm will be smaller.
dm.o: dm.c
	$(CC) $(CFLAGS) -DPTREE -c dm.c
dm.c: dm.y
	${YACC} dm.y
	$(MV) y.tab.c dm.c

DPRIME=dprime.o number.o z.o parseline.o ${GETOPT} 
UNTESTED = "This program has not been rigorously tested"
dprime: $(DPRIME)
	$(LINK) $(DPRIME) $(LIBS)
	@echo "dprime:" $(UNTESTED)

DSORT=dsort.o ${GETOPT} number.o parseline.o specol.o \
	numcmp.o readlines.o setint.o cistrcmp.o readmatrix.o
dsort: $(DSORT)
	$(LINK) $(DSORT)

FEATURES=features.o ${GETOPT} setint.o number.o
features: $(FEATURES)
	$(LINK) $(FEATURES)

FF=ff.o number.o ${GETOPT} setint.o filter.o fls.o
ff: $(FF)
	$(LINK) $(FF)

FPACK=fpack.o filter.o ${GETOPT}
fpack: $(FPACK)
	$(LINK) $(FPACK)

LINEX=linex.o number.o ${GETOPT} specol.o readlines.o
linex: $(LINEX)
	$(LINK) $(LINEX)

MAKETRIX=maketrix.o number.o getword.o ${GETOPT}
maketrix: $(MAKETRIX)
	$(LINK) $(MAKETRIX)

ONEWAY=oneway.o number.o ${GETOPT} getword.o f.o \
	setint.o setreal.o numline.o
oneway: $(ONEWAY)
	$(LINK) $(ONEWAY) $(LIBS)

PAIR=pair.o ${GETOPT} setint.o setreal.o number.o \
	f.o parseline.o numline.o
pair: pair.o $(PAIR)
	$(LINK) $(PAIR) $(LIBS)

PERM=perm.o random.o number.o ${GETOPT} setint.o \
	readlines.o numcmp.o cistrcmp.o
perm: $(PERM)
	$(LINK) $(PERM)

PROBDIST=probdist.o z.o chisq.o f.o number.o parseline.o random.o \
	${GETOPT} setint.o binomial.o prodlist.o primes.o
probdist: $(PROBDIST)
	$(LINK) $(PROBDIST) $(LIBS)

RANKIND=rankind.o getword.o centile.o ${GETOPT} setreal.o number.o \
	fisher.o prodlist.o primes.o chisq.o z.o setint.o fiveplot.o \
	numline.o ranksort.o ordstat.o chitest.o
rankind: $(RANKIND)
	$(LINK) $(RANKIND) $(LIBS)

RANKREL=rankrel.o parseline.o ${GETOPT} number.o setint.o binomial.o \
	centile.o prodlist.o primes.o chisq.o z.o ranksort.o ordstat.o cor.o f.o
rankrel: $(RANKREL)
	$(LINK) $(RANKREL) $(LIBS)

RANKSORT=setint.o number.o parseline.o ${GETOPT} 
ranksort: $(RANKSORT)
	$(CC) $(CFLAGS) -c -DRANKSORT ranksort.c
	$(LINK) ranksort.o $(RANKSORT)
	-$(RM) ranksort.o

REGRESS=regress.o parseline.o number.o f.o setint.o ${GETOPT} 
regress: $(REGRESS)
	$(LINK) $(REGRESS) $(LIBS)

REPEAT=repeat.o number.o ${GETOPT} setint.o readlines.o filter.o
repeat: $(REPEAT)
	$(LINK) $(REPEAT)

REVERSE=reverse.o ${GETOPT} parseline.o readlines.o
reverse: $(REVERSE)
	$(LINK) $(REVERSE)

SERIES=series.o number.o
series: $(SERIES)
	$(LINK) $(SERIES) $(LIBS)

STATS=stats.o number.o getword.o ${GETOPT} 
stats: $(STATS)
	$(LINK) $(STATS) $(LIBS)

TRANSPOSE=transpose.o parseline.o number.o ${GETOPT} setint.o
transpose: $(TRANSPOSE)
	$(LINK) $(TRANSPOSE)

TS=ts.o setint.o setreal.o number.o cor.o f.o barplot.o getword.o \
	${GETOPT} numline.o
ts: $(TS)
	$(LINK) $(TS) $(LIBS)

VALIDATA=validata.o parseline.o number.o ${GETOPT} 
validata: $(VALIDATA)
	$(LINK) $(VALIDATA)
