[ref1](https://github.com/segmentio/nightmare)
[ref2](http://codecept.io/nightmare/)
[ref3](https://segment.com/blog/ui-testing-with-nightmare/)

# Nightmare

Nightmare is a high-level browser automation.

Selenium WebDriver is considered to be standard for end to end testing of web applications. Despite its popularity it have its drawbacks, it requires a real browser and Selenium server to control it. This hardens setting it up testing environment for CI server and slows down test execution.

It was originally designed for automating tasks across sites that don't have APIs, but is most often used for UI testing and crawling.

# overview

Nightmare’s API methods are designed to mimic real user actions:

```
.goto(url)

.type(elementSelector, text)

.click(elementSelector)
```

This makes testing with Nightmare very similar to how a human tester would navigate, click and type into my actual web app. In the next few sections we’ll dive into how to set my repo, then how to test page loads, submitting forms, and interacting with an app.


# example 
```
import Nightmare from 'nightmare';
const nightmare = Nightmare({ show: true });

nightmare
  .goto('https://duckduckgo.com')
  .type('#search_form_input_homepage', 'github nightmare')
  .click('#search_button_homepage')
  .wait('#r1-0 a.result__a')
  .evaluate(() => document.querySelector('#r1-0 a.result__a').href)
  .end()
  .then(console.log)
  .catch((error) => {
    console.error('Search failed:', error);
  });
```