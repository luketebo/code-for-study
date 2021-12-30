// 横栏的固定
// 小横条的动画
// 顶部的一些小动画
var bar = document.getElementById("fz");
// 我没有找到fz
console.log(bar);
// 我现在要获取fz目前所处的位置
console.log(bar.offsetHeight, bar.offsetWidth);

$(function () {
  var navH = $("#fz").offset().top;
  //滚动事件
  $(window).scroll(function () {
    //获取滚动条的滑动距离
    var scroH = $(this).scrollTop();
    if (scroH >= navH) {
      $("#fz").css({ position: "fixed", top: 0, left: 0 });
    } else if (scroH < navH) {
      $("#fz").css({ position: "static", margin: "0,auto" });
    }
    console.log(scroH == navH);
  });
});
//图片运动
//var bg = document.getElementsByClassName(".qsong");
/*
var bg = $(".qsong");
console.log(bg);
var x = 80;
function polling() {
  bg.animate({"background-position-x":x+"%"},320,function(){
  bg.animate({"background-position-x":85+"%"},320,polling());
  })
}
function fy(){
  var ch = document.getElementsByClassName("qsong").mouseover = function (){
    ch.animate({"background-position-x":x+"%"},320,function(){
    ch.animate({"background-position-x":85 + "%"},320,polling());
    })
  }
 // polling();
}
*/
/*
var bg = document.getElementsByClassName(".qsong");
var mouse = document.getElementById("mouse");
document.onclick = function(){
  var event = event | window.event;
}
*/
/*
var x = 80;
var cg = document.getElementsByClassName("qsong");
console.log(cg);
for (var i = 0; i < cg.length; i++) {
  var x = 80;
  cg[i].onmouseover = function polling() {
    cg[i].animate({ "background-position-x": x + "%" }, 320, function () {
      cg[i].animate({ "background-position-x": 85 + "%" }, 320, polling());
    });
  };
  //console.log(cg[i]);
}
*/
/*
for(var ch in cg){
  ch.onmouseover = function(){
    alert("123");
  }
  console.log(ch);
}
*/
var bg = $(".qsong");
console.log(bg);
var x = 80;
function polling() {
  bg.animate({"background-position-x":x+"%"},320,function(){
  bg.animate({"background-position-x":85+"%"},320,polling())
  })
}
polling();
// 图片缩放
var mg = $("img");
console.log(mg);
for(var i = 0;i<mg.length;i++){
    mg[i].onmouseover = function(){
     
      $(this).css({"border-radius":4000})
    }

}
