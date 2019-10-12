The fundamental theorem of readability.

Code should be written to minimize the time it would take for someone else to understand it.
So even though having fewer lines of code is a good goal, minimizing the time-till-understanding is an even better goal.

**pack information into your names

(1) choose spectific words,

getPage -> doesn't really say much, does this method get a page from a local cache, from a database, or from the internet?

-> change to "fetchPage" or "DownloadPage"

(2) Finding more coloful words

send -> deliver, dispatch, announce, distribute, route
find -> search, extract, locate, recover
start-> launch, create, begin, open
make -> create, set up, build, generate, compose, add, new


(3)Avoid generic names like tmp and retval

The name retval(return value) doesn't pack much information. instead, use a name that describes the variable's value

if (right < left) {
	tmp = right;
	right = left;
	left = tmp;
}

In cases like these, the name tmp is perfectly fine, the variable's sole purpose is temporary storage, with a lifttime of only a few lines.
this variable has no other dutie. 


String tmp = user.name();
tmp += " " + user.phone_number();
tmp += " " + user.email();

...
template.set("user_info", tmp);

Even though this variable has a short lifespan, being temporary storage isn't the most important thing about this variable, Instead, a name
like user_info would be more descriptive.

The name tmp should be used only in cases when being short-lived and temporary is the most important fact about that variable.

If you're going to use a generic name like tmp, it, or retval, have a good reason for doing so.


**Prefer concreate names over abstract names

**Attaching Extra information to a name


var start = (new Date()).getTime();
var elapsed = (new Date()).getTime() - start;

These is nothing obviously wrong with this code, but it doesn't work, because getTime() returns milliseconds not seconds.

var start_ms = (new Date()).getTime();
var elapsed_ms = (new Date()).getTime() - start_ms;

** How long should a name be

(1) shorter names are okay for shorter scope.

if (debug) {
	map<string, int> m;
	LoopUpNamesNumbers(m);
	Print(m);
	
}

Even though m doesn't pack any information, it's not a problem, because the reader already has all the information she needs to understand this code.
However, suppose m were a class member or a global variable, and you saw this snippet of code:
	
LookUpNamesNumbers(m);
Print(m);

This code is much less readable, as it's unclear what the type or purpose of m is.
So, if an identifier has a large scope, the name needs to cary enough information to make it clear.

(2) Throwing out unneeded words

Sometimes words inside a name can be removed without losing any information at all. For instance, instead of ConvertToString(),
the name ToString() is smaller and doesn't lose any real information. Similarly, instead of DoServeLoop(), the name ServeLoop() is just as clear.

** usse capitalizatin, underscores, and so on in a meaningful way 
-for example, you can append "_" to class members to distinguish them from local variables.



***Names that can't be miscontrued

**Actively scrutinize your names by asking yourself, "Whar other meanings could someone interpret from this name?"

results = Database.all_objects.filter("year <= 2011")

(1) filter is an ambiguous word, It's unclear whether it means "to pick out" or "to get rid of" It's best to avoid
the name filter because it's so easily misconstrued.

def Clip(text, length);

(2) Clip 
• It removes length from the end
• It truncates to a maximum length


**The clearest way to name a limit is to put max_ or min_ infront of the thing being limited.

CART_TOO_BIG_LIMIT = 10
if shopping_cart.num_items() >= CART_TOO_BIG_LIMIT:
Error("Too many items in cart.")

the root problem is that CART_TOO_BIG_LIMIT is
an ambiguous name—it’s not clear whether you mean “up to” or “up to and including.”

When it comes to defining an upper or lower limit for a value, max_ and min_ are good prefixes
to use. For inclusive ranges, first and last are good. For inclusive/exclusive ranges, begin and
end are best because they’re the most idiomatic.

***Aesthetics

**Rearrange Line Breaks to Be Consistent and Compact

Here’s a more compact way to write the class:

public class PerformanceTester {
// TcpConnectionSimulator(throughput, latency, jitter, packet_loss)
// q			[Kbps] [ms] [ms] [percent]
public static final TcpConnectionSimulator wifi =
new TcpConnectionSimulator(500, 80, 200, 1);
public static final TcpConnectionSimulator t3_fiber =
new TcpConnectionSimulator(45000, 10, 0, 0);
public static final TcpConnectionSimulator cell =
new TcpConnectionSimulator(100, 400, 250, 5);
}


**Use Column Alignment When Helpful

**Pick a Meaningful Order, and Use It Consistently
• Match the order of the variables to the order of the <input> fields on the corresponding
HTML form.
• Order them from “most important” to “least important.”
• Order them alphabetically.

**Break Code into “Paragraphs”
Written text is broken into paragraphs for a number of reasons:
• It’s a way to group similar ideas together and set them apart from other ideas.
• It provides a visual “stepping stone”—without it, it’s easy to lose your place on the page.
• It facilitates navigation from one paragraph to another.



***Knowing what to comment

The purpose of commenting is to help the reader know as much as the writer did.

Even deep inside a function, it’s a good idea to comment on the “bigger picture.”

***Making Comments Precise and Compact

**Avoid Ambiguous Pronouns

**Describe Function Behavior Precisely

// Return the number of lines in this file.
int CountLines(string filename) { ... }

->

// Count how many newline bytes ('\n') are in the file.
int CountLines(string filename) { ... }


**Use Input/Output Examples That Illustrate Corner Cases

// Remove the suffix/prefix of 'chars' from the input 'src'.
String Strip(String src, String chars) { ... }

->

// Example: Strip("abba/a/ba", "ab") returns "/a/"
String Strip(String src, String chars) { ... }

---------------------------------------------------------------------------------------
Part 2

Simplifying Loops and Logic

***Making control flows easy to read

if (length >= 10) > if (10 <= length)
while (bytes_received < bytes_expected) > while (bytes_expected > bytes_received)

Left-hand side : The expression “being interrogated,” whose value is more in flux.
Right-hand side: The expression being compared against, whose value is more constant.

• Prefer dealing with the positive case first instead of the negative—e.g., if (debug) instead
of if (!debug).
• Prefer dealing with the simpler case first to get it out of the way. This approach might also
allow both the if and the else to be visible on the screen at the same time, which is nice.
• Prefer dealing with the more interesting or conspicuous case first.

-> depending on the details, this may be a judgment call.

**Instead of minimizing the number of lines, a better metric is to minimize the time needed for someone to understand it.
**By default, use an if/else. The ternary ?: should be used only for the simplest cases.

**In my experience, the do-statement is a source of errors and confusion. … I prefer the condition
“up front where I can see it.” Consequently, I tend to avoid do-statements.

**Returning Early from a Function

**Look at your code from a fresh perspective when you’re making changes. Step back and look at it as a whole.

**Removing Nesting by Returning Early

**Removing Nesting Inside Loops
for (int i = 0; i < results.size(); i++) {
	if (results[i] != NULL) {
		non_null_count++;
			if (results[i]->name != "") {
		cout << "Considering candidate..." << endl;
		...
		}
	}
}

Inside a loop, the analogous technique to returning early is to continue:
for (int i = 0; i < results.size(); i++) {
	if (results[i] == NULL) continue;
	non_null_count++;

	if (results[i]->name == "") continue;
	cout << "Considering candidate..." << endl;
...
}

---------------------------------------------------------------------------------------

1, generally speaking, the less code you write to slove a problem, the better. It probably takes less time to understand
a 2000-line class than a 5000-line class. but fewer lines isn't always better.

2, what about other constraints, like making code efficient, or well-architected, or easy to test, and so on?
Don't these sometimes conflict with wanting to make code easy to understand?

3, Of course, there's a lot more beneath the surface level when it comes to readability, but the material in this part is so
widely applicable, for so little effort, that its worth covering first.

4, As we mentioned before, a variable's name is like a tiny comment. even though there isn't much room, any extra information
you squeeze into a name will be seen every time the variable is seen.

5, Many security exploites come from not realizing that some data your program receives is not yet in a safe state.

6, Actively scrutinize your names by asking yourself, "Whar other meanings could someone interpret from this name?"

7, When it comes to defining an upper or lower limit for a value, max_ and min_ are good prefixes to use.
For inclusive ranges, first and last are good. For inclusive/exclusive ranges,
begin and end are best because they’re the most idiomatic.

8, Use Column Alignment When Helpful

9, Pick a Meaningful Order, and Use It Consistently

10, The purpose of commenting is to help the reader know as much as the writer did.

11, Don't comment on facts that can be derived quickly from the code itself

12, Don't comment BAD names - Fix the names instead.

13, Consider this thought experiment: someone new just joined your team, she’s sitting next
to you, and you need to get her familiar with the codebase.

14, Our advice is to do whatever helps the reader understand the code more easily. This may involve
commenting the what, the how, or the why (or all three).

Notice that we’ve broken down the task of writing a comment into these simpler steps:
1. Write down whatever comment is on your mind.
2. Read the comment, and see what (if anything) needs to be improved.
3. Make improvements.

What not to comment:
• Facts that can be quickly derived from the code itself.
• “Crutch comments” that make up for bad code (such as a bad function name)—fix the
code instead.
Thoughts you should be recording include:
• Insights about why code is one way and not another (“director commentary”).
• Flaws in your code, by using markers like TODO: or XXX:.
• The “story” for how a constant got its value.
Put yourself in the reader’s shoes:
• Anticipate which parts of your code will make readers say “Huh?” and comment those.
• Document any surprising behavior an average reader wouldn’t expect.
• Use “big picture” comments at the file/class level to explain how all the pieces fit together.
• Summarize blocks of code with comments so that the reader doesn’t get lost in the details.


-----------------------------------------------------------------------------------------
