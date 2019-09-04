$(document).ready(function () {
    $('#pads > div').click(function (e) { 
        e.preventDefault();
        var pad = $(this);
        var audio = pad[0].children[0]
        audio.currentTime = 0
        audio.play();
        //make pad look like it was clicked
        pad.css('border', '5px solid black');
        setTimeout(function(){ 
            pad.css('border', '0px solid black');
        }, 100);
        //change background color
        var colour = pad.css('background');
        $('body').css('background', colour);
    });
});