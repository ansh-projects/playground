$(document).ready(function () {
    var rn = 0;
    var guess = -1;
    var rnr = -1;
    var guess_num = 0;

    rn = Math.random() * 10 + 1;
    rnr = Math.floor(rn);
    console.log(rnr);

    function guessed() {
        var input = document.getElementById("userInput").value;
        if (input != null) {
            guess = input;
        } else {
            alert("no input");
        }
        if (guess == rnr) {
            alert("YOU WIN");
            console.log("ayy");
        } else {
            $("#append").appendTo("<p>" + i + "</p>");
        }
    }
});