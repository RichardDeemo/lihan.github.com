while(true){//����һ����ѭ��һֱ��ѯ�Ƿ���΢���������
    // console.show();
    if(currentActivity().search("com.tencent.mm") == -1){//��ǰAPP����΢��
    //launch("com.tencent.mm");
    console.log("if ��ǰactivity="+currentActivity());
    launch("com.tencent.mm");//��΢��
    sleep(2000);
    }else{
    while(true){
        var c = id("iot").find();//ԭ�������࣬һ����iot ��һ����x9 �����������λ
        c.each(function(btn) {
            tryFav(btn);
        });
        var d = id("x9").find();
        d.each(function(btn) {
            tryFav(btn);
        });
        
        scroll();//������ɵ�ǰҳ��������һҳ
        sleep(1000);
    }
    }
}

function tryFav(btn) {
    var b = btn.bounds();
    toast(b.centerX() + "####" + b.centerY());//�������λ�ã������ж��Ƿ���ȷ
    while(!click(b.centerX()-10, b.centerY()+10));
    sleep(1000);
    if (id("bah").find().empty()) {//�����ǰ����ϸ���棬����
        back();
    }
    sleep(1000);
}

function scroll() {
    className("ListView").scrollForward();
}

//xiahua
