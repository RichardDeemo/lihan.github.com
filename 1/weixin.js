while(true){//定义一个死循环一直查询是否在微信聊天界面
    // console.show();
    if(currentActivity().search("com.tencent.mm") == -1){//当前APP不是微信
    //launch("com.tencent.mm");
    console.log("if 当前activity="+currentActivity());
    launch("com.tencent.mm");//打开微信
    sleep(2000);
    }else{
    while(true){
        var c = id("iot").find();//原点有两类，一个是iot ，一个是x9 。我们逐个定位
        c.each(function(btn) {
            tryFav(btn);
        });
        var d = id("x9").find();
        d.each(function(btn) {
            tryFav(btn);
        });
        
        scroll();//操作完成当前页，进入下一页
        sleep(1000);
    }
    }
}

function tryFav(btn) {
    var b = btn.bounds();
    toast(b.centerX() + "####" + b.centerY());//弹出点击位置，方便判断是否正确
    while(!click(b.centerX()-10, b.centerY()+10));
    sleep(1000);
    if (id("bah").find().empty()) {//如果当前是详细界面，返回
        back();
    }
    sleep(1000);
}

function scroll() {
    className("ListView").scrollForward();
}

//xiahua
