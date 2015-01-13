var testCase = require('nodeunit').testCase;
var exec = require('child_process').exec;
var colors = require('colors');
var diff = require('diff');
var fs = require('fs');

module.exports = testCase({
    'ex00': testCase({
        'test': function(test) {
            exec("/tmp/epitech-tests/test00 | cat -e", function(err, stdout, stderr) {
                if (err) {
                    test.ok(false);
                    test.done();
                } else {
                    fs.readFile("/tmp/epitech-tests/ex00/outputs/out1", function(err, data) {
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
    }),
    'ex01': testCase({
        'test': function(test) {
            exec("/tmp/epitech-tests/test01 | cat -e", function(err, stdout, stderr) {
                if (err) {
                    test.ok(false);
                    test.done();
                } else {
                    fs.readFile("/tmp/epitech-tests/ex01/outputs/out1", function(err, data) {
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
    }),
    'ex02': testCase({
        'Starfleet Ship': function(test) {
            exec("/tmp/epitech-tests/test02 1", function(err, stdout, stderr) {
                if (err) {
                    test.ok(false);
                    test.done();
                } else {
                    fs.readFile("/tmp/epitech-tests/ex02/outputs/out1", function(err, data) {
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
	},
        'Indepentant Ship': function(test) {
	    exec("/tmp/epitech-tests/test02 2", function(err, stdout, stderr) {
                if (err) {
                    test.ok(false);
                    test.done();
                } else {
                    fs.readFile("/tmp/epitech-tests/ex02/outputs/out2", function(err, data) {
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
	},
        'Borg Ship': function(test) {
            exec("/tmp/epitech-tests/test02 3", function(err, stdout, stderr) {
                if (err) {
                    test.ok(false);
                    test.done();
                } else {
                    fs.readFile("/tmp/epitech-tests/ex02/outputs/out3", function(err, data) {
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
        },
        'Test previous exercises': function(test) {
            exec("/tmp/epitech-tests/test02 4", function(err, stdout, stderr) {
                if (err) {
                    test.ok(false);
                    test.done();
                } else {
                    fs.readFile("/tmp/epitech-tests/ex02/outputs/out4", function(err, data) {
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
    }),
    'ex03': testCase({
	'test': function(test) {
	    exec("/tmp/epitech-tests/test03 | cat -e", function(err, stdout, stderr) {
                if (err) {
                    test.ok(false);
                    test.done();
                } else {
                    fs.readFile("/tmp/epitech-tests/ex03/outputs/out1", function(err, data) {
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
    }),
    'ex04': testCase({
	'test': function(test) {
	    exec("/tmp/epitech-tests/test04", function(err, stdout, stderr) {
                if (err) {
                    test.ok(false);
                    test.done();
                } else {
                    fs.readFile("/tmp/epitech-tests/ex04/outputs/out1", function(err, data) {
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
    }),
    'ex05': testCase({
	'test': function(test) {
	    exec("/tmp/epitech-tests/test05 | cat -e", function(err, stdout, stderr) {
                if (err) {
                    test.ok(false);
                    test.done();
                } else {
                    fs.readFile("/tmp/epitech-tests/ex05/outputs/out1", function(err, data) {
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
