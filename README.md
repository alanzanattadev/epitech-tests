# Credits

Tests from d09 (from ex00 to ex04) were written by [Maxime Didier](https://plus.google.com/108527613900262869397).
All the other tests were written by [Louis Brunner](https://github.com/Hyrrmadr).

# epitech-tests

## Install
* `cd [folder to clone the repo in]`
* `git clone`
* `sudo mv epitech-tests /usr/bin`
* `sudo ln -s /usr/bin/epitech-tests/tek /usr/bin/tek`
* `cd /usr/bin/epitech-tests/`
* `sudo npm -g install nodeunit`
* `sudo npm install`

## Usage
```tek [OPTIONS...]```: a small script that lets you check your projects with some unit tests.

```tek [PROJECT NAME]```: Runs all the tests for the given project and shows you the failures. _Passing all tests does not guarantee a perfect mark._

```tek update```: Check if new tests or features are available, in which case an update is performed.

```tek help```: Displays this help.

## Add tests
In the project folder (ex: tek2/piscine/d09/), create a new directory tested part of the project (ex: ex00) and add a Makefile to compile this part of the project with all the tests.

If the _tests.js_ file exists, add a tests to the ```testCase();```:
```javascript
module.exports = testCase({
    [...]
    '[PART TO TEST]': testCase(tests.getTestCase("[TEST NAME]",	"[BINARY CREATED BEFORE]",	"[AWAITED OUTPUT]")),
    [...]
});

```

Else, create it and add this code snippet:
```javascript
var testCase = require('nodeunit').testCase;
var tests = require('../../../tests.js');

module.exports = testCase({
    '[PART TO TEST]': testCase(tests.getTestCase("[TEST NAME]",	"[BINARY CREATED BEFORE]",	"[AWAITED OUTPUT]"))
});

```
