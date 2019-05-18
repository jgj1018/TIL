* Consider someone approaching you with the claim that “my program is perfect” (i.e., error free). The best way to establish some confidence in this claim is to try to refute it, that is, to try to find imperfections rather than just confirm that the program works correctly for some set of input data.


* If you want to use this approach to find all errors in the program, the criterion is exhaustive input testing, making use of every possible input condition as a test case.


* This discussion shows that exhaustive input testing is impossible. Two important implications of this: (1) You cannot test a program to guarantee that it is error free; and (2) a fundamental consideration in program testing is one of economics. Thus, since exhaustive testing is out of the question, the objective should be to maximize the yield on the testing investment by maximizing the number of errors found by a finite number of test cases.


* Another testing strategy, white-box (or logic-driven) testing, permits you to examine the internal structure of the program. This strategy derives test data from an examination of the program's logic (and often, unfortunately, at the neglect of the specification).


* Testing is the process of executing a program with the intent of finding errors. Testing is more successful when not performed by the developer(s). A good test case is one that has a high probability of detecting an undiscovered error. A successful test case is one that detects an undiscovered error. Successful testing includes carefully defining expected output as well as input. Successful testing includes carefully studying test results.


* The three primary human testing methods are code inspections, walkthroughs and user (or usability) testing. We cover the first two of these, which are code-oriented methods, in this chapter. These methods can be used at virtually any stage of software development, after an application is deemed to be complete or as each module or unit is complete (see Chapter 5 for more information on module testing). 


*  The implication is that inspections/walkthroughs and computer-based testing are complementary; error-detection efficiency will suffer if one or the other is not present.


*  modifying an existing program is a process that is more error prone (in terms of errors per statement written) than writing a new program. 

* The programmer narrates, statement by statement, the logic of the program. During the discourse, other participants should raise questions, which should be pursued to determine whether errors exist. It is likely that the programmer, rather than the other team members, will find many of the errors identified during this narration. In other words, the simple act of reading aloud a program to an audience seems to be a remarkably effective error-detection technique.