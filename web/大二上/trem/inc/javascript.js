// 横栏的固定
// 小横条的动画
// 顶部的一些小动画
var x = $(".second_list");
console.log(x);
x.css({ display: "none" });
var bar = document.getElementById("fz");

// 我现在要获取fz目前所处的位置
console.log(bar.offsetHeight, bar.offsetWidth);
/*
 static：无特殊定位，对象遵循正常文档流。top，right，bottom，left等属性不会被应用。
 relative：对象遵循正常文档流，但将依据top，right，bottom，left等属性在正常文档流中偏移位置。而其层叠通过z-index属性定义。
 absolute：对象脱离正常文档流，使用top，right，bottom，left等属性进行绝对定位。而其层叠通过z-index属性定义。
 fixed：对象脱离正常文档流，使用top，right，bottom，left等属性以窗口为参考点进行定位，当出现滚动条时，对象不会随着滚动。而其层叠通过z-index属性定义。
  scrollTop() 方法设置或返回被选元素的垂直滚动条位置。
 */
$(function () {
  var navH = $("#fz").offset().top;  //返回偏移坐标
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

var bg = $(".qsong");

var x = 80;
function polling() {
  bg.animate({ "background-position-x": x + "%" }, 320, function () {
    bg.animate({ "background-position-x": 85 + "%" }, 320, polling());
  });
}
polling();
// 图片缩放
var mg = $("img");

$(function () {
  var w = $("img").width();
  var h = $("img").height();
  var w2 = w + 20;
  var h2 = h + 20;
  //stop 是jQuery中用于控制页面动画效果的方法。运行之后立刻结束当前页面上的动画效果。
  /*
  hover() 方法规定当鼠标指针悬停在被选元素上时要运行的两个函数。 
  方法触发 mouseenter 和 mouseleave 事件。
  (selector).animate({styles},speed,easing,callback)
  */
  $("img").hover(
    function () {
      $(this).stop().animate({ height: h2, width: w2 }, 400);
    },
    function () {
      $(this).stop().animate({ height: h, width: w }, 400);
    }
  );
});
// 跳转页面

//console.log(sec);
var t2 = document.getElementById("t2");
var t1 = document.getElementById("cacb");
//console.log(t1);
t2.onclick = function () {
  var news = $(".news_list");
  var sec = $(".second_list");
  // this.css({color:"#dda004c5"});
  this.style.color = "#ab8c40";
  t1.style.color = "black";

  news.css({ display: "none" });
  sec.css({ display: "block" });
  //console.log(sec);
};
t1.onclick = function () {
  var news = $(".news_list");
  var sec = $(".second_list"); 
  // this.css({color:"#dda004c5"});
  this.style.color = "#ab8c40";
  t2.style.color = "black";

  news.css({ display: "block" });
  sec.css({ display: "none" });
  //  console.log(sec);
};

