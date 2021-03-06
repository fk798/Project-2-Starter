// Import the ORM to create functions that will interact with the database.
var orm = require("../config/orm.js");

var scan = {
  all: function(cb) {
    orm.all("scan", function(res) {
      cb(res);
    });
  },
  // The variables cols and vals are arrays.
  create: function(cols, vals, cb) {
    orm.create("scan", cols, vals, function(res) {
      cb(res);
    });
  },
  update: function(objColVals, condition, cb) {
    orm.update("scan", objColVals, condition, function(res) {
      cb(res);
    });
  },
  delete: function(condition, cb) {
    orm.delete("scan", condition, function(res) {
      cb(res);
    });
  }
};

module.exports = scan;
