var connection = require("../config/connection.js");

//create selectAll(), insertOne(), and updateOne().
var orm = {
all: function(param1, cb){
    var queryString = "SELECT * FROM " + param1 + ";";
    connection.query(queryString,function(err,result){
        if(err) {
            throw err;
        }
        cb(result);
    });
},
create: function(table,cols,vals,cb){
    var queryString = "INSERT INTO "+ table;

    queryString +=" (";
    queryString += cols.toString();
    queryString +=") ";
    queryString += "VALUES (";
    queryString += scanIt(vals.length);
    queryString +=") ";

    console.log(queryString);

    connection.query(queryString,vals, function(err, result){
        if(err) {
            throw err;
        }

        cb(result);
    });

},

update: function(table, objColVals, condition, cb){
    var queryString = "UPDATE " + table;

    queryString += " SET ";
    queryString += objtoSQL(objColVals);
    queryString += " WHERE ";
    queryString += condition;

    console.log(queryString);
    connection.query(queryString, function(err, result){
        if (err) {
            throw err;
        }

        cb(result);
    })
},

delete: function(table, condition, cb){
    var queryString = "DELETE FROM " + table;
    queryString += " WHERE ";
    queryString += condition;

    connection.query(queryString, function(err, result){
        if (err) {
            throw err;
        }

        cb(result);
    });
}
};

module.exports = orm; //look up the syntax
