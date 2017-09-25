function add() {
    $.ajax ({
        url: 'tasks.php',
        method: 'POST',
        data: { task: $( "#add" )[0].value, action: "PUT" },
        success: function(){
            var elem = $( "#add" );
            var td = elem.parent();
            elem.after('<img src="img/check.png" onclick="window.location.href=\'success.php?task=' + tasks + '\'">' + elem[0].value);
            elem.remove();
            var next = td.next();
            if( next.length == 0 ) {
                var row = td.parent();
                row.after('<tr><td><input id="add" onchange="add()"></td><td style="visibility: hidden;"></td><td style="visibility: hidden;"></td></tr>');
            } else {
                next.css("visibility", "visible");
                next.html('<input id="add" onchange="add()">');
            }
            $( "#add" ).focus();
            $('#add').keypress(function (e) {
             var key = e.which;
             if(key == 13)  // the enter key code
              {
                $('#add').trigger("change");
                return false;  
              }
            });
            tasks++;
        }
    });
}
$('#add').keypress(function (e) {
 var key = e.which;
 if(key == 13)  // the enter key code
  {
    $('#add').trigger("change");
    return false;  
  }
});

// Set the date we're counting down to
var length = 5*60;
var countDownDate = new Date().getTime() + 1000*length;

function update() {
  if( $("#timer").length == 0 )
    return false;

  // Get todays date and time
  var now = new Date().getTime();

  // Find the distance between now an the count down date
  var distance = countDownDate - now;
  
  // If the count down is finished, go back to work
  if (distance <= 0) {
      window.location.href = "todo.php?work";
      return true;
  }

  // Time calculations for days, hours, minutes and seconds
  var days = Math.floor(distance / (1000 * 60 * 60 * 24));
  var hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
  var minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
  var seconds = Math.floor((distance % (1000 * 60)) / 1000);

  // Display the result in the element with id="demo"
  document.getElementById("timer").innerHTML = minutes + ":" + (seconds < 10 ? "0" + seconds : seconds);
  
  $( "figure > div > div" ).css("width", ((1 + 1.0*seconds + 60*minutes + 60*60*hours + 60*60*24*days ) / length)*100 + "%");
  $( "figure > div > div" ).animate({"width": ((1.0*seconds + 60*minutes + 60*60*hours + 60*60*24*days ) / length)*100 + "%"}, 1000, "linear");
  
  return true;
}

if( update )
    setInterval(update, 1000);
