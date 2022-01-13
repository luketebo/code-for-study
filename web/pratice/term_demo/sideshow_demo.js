$(function(){
    var i = 0;
    var timer = null;
    var delay = 1000;
    var width = 958;
    var speed = 400;
    var firstImg = $(".hot li").first().clone();
    $(".hot").append(firstImg).width($(".hot li").length * width);
    // 1.设置周期计时器，实现图片自动切换
    timer = setInterval(imgChange,delay);
    // 2.鼠标移入暂停自动播放，移出，开始播放
    $(".banner").hover(function (){
        clearInterval(timer);
    },function(){
        timer = setInterval(imgChange,delay);
    });
    // 3.鼠标划过圆点
    $(".dot li").mouseover(function(){
        i = $(this).index();
        $(".hot").stop().animate({left:-i * width},200);
        dotChange();
    });
    // 4.设置左右切换的箭头显示和隐藏
    $(".banner").hover(function(){
        $(".arrow").show();
    },function(){
        $(".arrow").hide();
    });
    // 5.向右箭头
    $(".next").click(function(){
        imgChange();
    });
    // 6.向左箭头
    $(".prev").click(function(){
        --i;
        if(i==-1){
            i = $(".hot li").length - 2;
            $(".hot").css({left:-($(".hot li").length - 1) * width});
        }
        $(".hot").stop().animate({left : -i * width},speed);
        dotChange();
    });
    // 自动切换图片
    function imgChange(){
        ++i;
        isCrack();
        dotChange();
    }
    // 无缝轮播
    function isCrack(){
        if(i == $(".hot li").length){
            i = 1;
            $(".hot").css({left : 0});
        }
        $(".hot").stop().animate({left : -i * width},speed);
    }
    // 自动切换对应的圆点
    function dotChange(){
        if( i == $(".hot li").length - 1){
            $(".dot li").eq(0).addClass("on").siblings().removeClass("on");
        }else {
            $(".dot li").eq(i).addClass("on").siblings().removeClass("on");
        }
    }
})
/**
 * 可以简化，就是不加箭头和圆点，这样简化的轮播图也是可以完成效果的
 */

$(function(){
    var i = 0;
    var timer = null;
    var delay = 1000;
    var width = 958;
    var speed = 400;
    var firstImg = $(".hot li").first().clone();
    $(".hot").append(firstImg).width($(".hot li").length * width);
    timer = setInterval(imgChange,delay);
    $(".banner").hover(function(){
        clearInterval(timer);
    },function(){
        timer = setInterval(imgChange,delay);
    })
    function imgChange(){
        ++i;
        isCrack();
      //  dotChange(); // 圆点
    }
    function isCrack(){
        if(i == $(".hot li").length){
            i = 1;
            $(".hot").css({left : 0});
        }
        $(".hot").stop().animate({left : -i * width},speed);
    }
    // $(".dot li").mouseover(function(){
    //     i = $(this).index();
    //     $(".hot").stop().animate({left : -i * width},200);
    //     dotChange();
    // })
})
// 第二次试手
$(function (){
    var i = 0;   // 索引
    var timer = null;  // 定时器
    var delay = 1000;   // 设置切换间隔时间
    var width = 958;   // 图片宽度
    var speed = 400;   // 动画时间
    var firstImg = $(".hot li").first().clone();
    $(".hot").append(firstImg).width($(".hot li").length * width);
    timer = setInterval(imgChange,delay);
    $(".banner").hover(function(){
        clearInterval(timer);
    },function(){
        timer = setInterval(imgChange,delay);
    })
    function imgChange(){
        ++i;
        isCrack();
    }
    // 自动切换图片
    function isCrack(){
        if( i == $(".hot li").length){
            i = 1;
            $(".hot").css({left:0});
        }
        $(".hot").stop().animate({left: -i * width},speed);
    }
})