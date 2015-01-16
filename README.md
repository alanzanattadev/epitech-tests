# epitech-tests

## Install
* cd [folder to clone the repo in]
* git clone
* sudo mv epitech-tests /usr/bin
* sudo ln -s /usr/bin/epitech-tests/tek /usr/bin/tek
* cd /usr/bin/epitech-tests/
* sudo npm -g install nodeunit
* sudo npm install

## Usage
```tek [OPTIONS...]```: a small script that allows you to check your projects with some unittests.

```tek [PROJECT NAME]```: Run all the tests for the given project and informs you of which tests doesn't pass the assertions. If you program pass all the tests, it does not mean that you gonna get all the points when corrected!

```tek update```: Check if new tests are available, and if so process an update by fetching them.

```tek help```: Displays this help.

## Add tests
In the folder of the test (ex: tek2/piscine/d09/), create a new folder corresponding to the part of the projet tested (ex: ex00) and add a Makefile to compile this part of the project with all the tests.

If the _tests.js_ file exists, add a tests to the ```testCase();```:
```
module.exports = testCase({
    [...]
    '[PART TO TEST]': testCase(tests.getTestCase("[TEST NAME]",	"[BINARY CREATED BEFORE]",	"[AWAITED OUTPUT]")),
    [...]
});

```

If the _tests.js_ file doesn't exists, create one and add this code snippet:
```
var testCase = require('nodeunit').testCase;
var tests = require('../../../tests.js');

module.exports = testCase({
    '[PART TO TEST]': testCase(tests.getTestCase("[TEST NAME]",	"[BINARY CREATED BEFORE]",	"[AWAITED OUTPUT]"))
});

```