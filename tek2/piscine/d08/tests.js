var testCase = require('nodeunit').testCase;
var exec = require('child_process').exec;
var colors = require('colors');
var diff = require('diff');
var fs = require('fs');

module.exports = testCase({
    'ex00': testCase({
        'Basic droids': function(test) {
            exec("/tmp/epitech-tests/test00 | cat -e", function(err, stdout, stderr) {
                if (err) {
                    test.ok(false);
                    test.done();
                } else {
                    fs.readFile("/tmp/epitech-tests/ex00/outputs/out", function(err, data) {
                        if (err) {
                            test.ok(false);
                        } else {
                            if (data.toString() != stdout) {
                                var d = diff.diffLines(stdout, data.toString());
                                d.forEach(function(part) {
                                    var color = part.added ? 'green' : part.removed ? 'red' : 'grey';
                                    process.stderr.write(part.value[color]);
                                });
                            }
                            test.equal(stdout, data.toString());
                        }
                        test.done();
                    });
                }
            });
        }
    })
});
