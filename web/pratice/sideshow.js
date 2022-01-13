// 实现图片无缝切换
$(function () {
  var width = 958;
  var firstimg = $(".hot li").first().clone();
  $(".hot")
    .append(firstimg)  
    //append ()函数用于向每个匹配元素内部的末尾位置追加指定的内容。
    .width($(".hot li").length * width);
});
// 实现图片自动切换
var timer = null;
var dalay = 1000;
timer = setInterval(img_change, dalay);
var i = 0;
function img_change() {
  ++i;
  isCrack();
  dotChange();
 // console.log(i);
}
var speed = 400;
var width = 958;
console.log($(".hot li").length);
function isCrack() {
  if (i == $(".hot li").length) {
    i = 1;
    $(".hot li").css({ left: 0 });
  }
  $(".hot")
    .stop()
    .animate({ left: -i * width }, speed);
}
// 为图片添加小圆点
function dotChange() {
  if (i == $(".hot li").length - 1) {
    //eq (index) 方法将匹配元素集缩减值指定 index 上的一个。
    //整数，指示元素的位置（最小为 0）。
    //如果是负数，则从集合中的最后一个元素往回计数
    $(".hot li").eq(0).addClass("on").siblings().removeClass("on");
  } else {
    $(".hot li").eq(i).addClass("on").siblings().removeClass("on");
  }
}
$(".banner").hover(
  function () {
    clearInterval(timer);
  },
  function () {
    timer = setInterval(img_change, dalay);
  }
);
// 鼠标滑过圆点
$(".dot li").mouseover(function () {
  i = $(this).index();
  $(".hot")
    .stop()
    .animate({ left: -i * width }, 200);
  dotChange();
});
// 利用箭头左右切换
$(".banner").hover(
  function () {
    $(".arrow").show();
  },
  function () {
    $("arrow").hide();
  }
);
$(".next").click(function () {
  img_change();
});
$(".prev").click(function () {
  i--;
  if (i == -1) {
    i = $(".hot li").length - 2;
    $(".hot").css({ left: -($(".hot li").lenth - 1) * width });
  }
  $(".hot")
    .stop()
    .animate({ left: -i * width }, speed);
  dotChange();
});
