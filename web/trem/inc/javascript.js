/*
function $(a) {
  return document.getElementById(a);
}

var po = $("fz").offsetTop;



$("fz").style.position = "fixed";
$("fz").style.top = $("logo").offsetHeight + "px";

function stay(ss) {
  var objY = $("fz").offsetTop;
  var objS = $("fz").style;
  if (ss >= $("logo").offsetHeight) objS.top = 0;
  else objS.top = -1 * ss + $("logo").offsetHeight - 2 + "px";
  console.log(objY);
}
*/
/*
window.addEventListener("scroll", function () {
  var top = window.pageYOffset || 0;
  window.requestAnimationFrame(function () {
      stay(top);
      ticking = false;
  });
});
*/
/*
$("#container")
  .find("img")
  .each(function () {
    var img = this;
    if (img.width > 30) {
      img.style.width = "30px";
      img.style.height = "30px";
      //$(img).removeAttr('height');
      
      var aTag = document.createElement('a');
      aTag.href = img.src;
            aTag.target="_blank";
      $(aTag).addClass('bPic')
      .insertAfter(img).append(img)
      .lightBox(options);
     
    }
  }); 
  */

var ele = $("imgs");
ele.offsetHeight = 30 + "px";
ele.offsetWeight = 30 + "px";
console.log("imgs " + ele.offsetHeight + " 高 " + ele.offsetWeight);


