var testCase = require('nodeunit').testCase;
var tests = require('../../../tests.js');

console.log("\x1b[36mWe <3 Zizi-Superstar !\x1b[0m");

module.exports = testCase({
    'ex00': testCase(tests.getTestCase("Encapsulation",		"/tmp/epitech-tests/test00",		"/tmp/epitech-tests/ex00/outputs/out1")),
});
