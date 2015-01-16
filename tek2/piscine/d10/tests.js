var testCase = require('nodeunit').testCase;
var tests = require('../../../tests.js');

module.exports = testCase({
    'ex00': testCase(tests.getTestCase("test",		"/tmp/epitech-tests/test00",		"/tmp/epitech-tests/ex00/outputs/out1"))
});
