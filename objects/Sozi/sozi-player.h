#ifndef SOZI_PLAYER_H
#define SOZI_PLAYER_H

static const char sozi_min_js[] =
"function namespace(b,d,a){var c=b;d.split(\".\").forEach(function(e){if(typeof c[e"
"]===\"undefined\"){c[e]={}}c=c[e]});if(a){a(c,b)}return c}namespace(this,\"sozi.eve"
"nts\",function(b){var a={};b.listen=function(c,d){if(!a.hasOwnProperty(c)){a[c]=["
"]}a[c].push(d)};b.fire=function(d){var c=Array.prototype.slice.call(arguments,1)"
";if(a.hasOwnProperty(d)){a[d].forEach(function(e){e.apply(null,c)})}}});namespac"
"e(this,\"sozi.proto\",function(a){a.Object={installConstructors:function(){functio"
"n b(){}b.prototype=this;this.instance=function(){var c=new b();c.construct.apply"
"(c,arguments);return c};this.subtype=function(d){var c=new b();c.augment(d);c.in"
"stallConstructors();return c}},construct:function(){},augment:function(c){for(va"
"r b in c){if(c.hasOwnProperty(b)){this[b]=c[b]}}return this},bind:function(c){va"
"r b=this;return function(){return c.apply(b,arguments)}}};a.Object.installConstr"
"uctors()});namespace(this,\"sozi.actions\",function(A,g){var u=namespace(g,\"sozi.p"
"layer\");var v=namespace(g,\"sozi.display\");var n=g.document;var o=0;var w=1;var t"
"=1.05;var y=5;var m=5;var r=false;var i=0;var h=0;function a(C,B,D){u.stop();v.v"
"iewPorts.player.zoom(C>0?t:1/t,B,D)}function x(B){u.stop();v.viewPorts.player.ro"
"tate(B>0?y:-y)}function s(){if(sozi.framelist.isVisible()){sozi.framelist.hide()"
";u.restart()}else{u.stop();sozi.framelist.show()}}function d(B){return v.viewPor"
"ts.player.contains(B.clientX,B.clientY)}function f(B){if(!d(B)){return}if(B.butt"
"on===o){n.documentElement.addEventListener(\"mousemove\",q,false);r=false;i=B.clie"
"ntX;h=B.clientY}else{if(B.button===w){s()}}B.stopPropagation();B.preventDefault("
")}function q(B){if(!d(B)){return}u.stop();if(!r&&(Math.abs(B.clientX-i)>m||Math."
"abs(B.clientY-h)>m)){r=true}if(r){sozi.events.fire(\"sozi.player.cleanup\");v.view"
"Ports.player.drag(B.clientX-i,B.clientY-h);i=B.clientX;h=B.clientY}B.stopPropaga"
"tion()}function c(B){if(!d(B)){return}if(B.button===o){n.documentElement.removeE"
"ventListener(\"mousemove\",q,false)}B.stopPropagation();B.preventDefault()}functio"
"n p(B){if(!d(B)){return}u.moveToPrevious();B.stopPropagation();B.preventDefault("
")}function e(B){if(!d(B)){return}if(!r&&B.button!==w){u.moveToNext()}B.stopPropa"
"gation();B.preventDefault()}function j(B){if(!d(B)){return}if(!B){B=g.event}var "
"C=0;if(B.wheelDelta){C=B.wheelDelta}else{if(B.detail){C=-B.detail}}if(C!==0){if("
"B.shiftKey){x(C)}else{a(C,B.clientX,B.clientY)}}B.stopPropagation();B.preventDef"
"ault()}function l(B){if(B.altKey||B.ctrlKey||B.metaKey){return}switch(B.charCode"
"||B.which){case 43:a(1,g.innerWidth/2,g.innerHeight/2);break;case 45:a(-1,g.inne"
"rWidth/2,g.innerHeight/2);break;case 61:u.moveToCurrent();break;case 70:case 102"
":u.showAll();break;case 84:case 116:s();break;case 82:x(-1);break;case 114:x(1);"
"break;default:return}B.stopPropagation();B.preventDefault()}function b(B){if(B.a"
"ltKey||B.ctrlKey||B.metaKey){return}switch(B.keyCode){case 36:if(B.shiftKey){u.j"
"umpToFirst()}else{u.moveToFirst()}break;case 35:if(B.shiftKey){u.jumpToLast()}el"
"se{u.moveToLast()}break;case 38:case 33:case 37:if(B.shiftKey){u.jumpToPrevious("
")}else{u.moveToPrevious()}break;case 40:case 34:case 39:case 13:case 32:if(B.shi"
"ftKey){u.jumpToNext()}else{u.moveToNext()}break;default:return}B.stopPropagation"
"();B.preventDefault()}function z(B){B.stopPropagation()}function k(){var C=n.get"
"ElementsByTagName(\"a\");for(var D=0;D<C.length;D+=1){C[D].addEventListener(\"click"
"\",z,false);C[D].addEventListener(\"contextmenu\",z,false)}var B=n.documentElement;"
"B.addEventListener(\"click\",e,false);B.addEventListener(\"mousedown\",f,false);B.ad"
"dEventListener(\"mouseup\",c,false);B.addEventListener(\"contextmenu\",p,false);B.ad"
"dEventListener(\"DOMMouseScroll\",j,false);g.onmousewheel=j;B.addEventListener(\"ke"
"ypress\",l,false);B.addEventListener(\"keydown\",b,false)}sozi.events.listen(\"sozi."
"display.ready\",k)});namespace(this,\"sozi.animation\",function(d,g){var h=g.mozReq"
"uestAnimationFrame||g.webkitRequestAnimationFrame||g.msRequestAnimationFrame||g."
"oRequestAnimationFrame;var k=function(){return g.performance&&g.performance.now?"
"g.performance.now():Date.now()};d.setAnimationFrameHandlers=function(l,m){h=l;k="
"m};var i=40;var c;var j=[];function e(){if(j.length>0){if(h){h(e)}j.forEach(func"
"tion(l){l.step(k())})}else{if(!h){g.clearInterval(c)}}}function b(){if(h){h(e)}e"
"lse{c=g.setInterval(function(){e(k())},i)}}function a(l){j.push(l);if(j.length=="
"=1){b()}}function f(l){j.splice(j.indexOf(l),1)}d.Animator=sozi.proto.Object.sub"
"type({construct:function(){this.durationMs=0;this.data=null;this.initialTime=0;t"
"his.started=false},start:function(l,m){this.durationMs=l;this.data=m;this.initia"
"lTime=k();this.onStep(0);if(!this.started){this.started=true;a(this)}},stop:func"
"tion(){if(this.started){f(this);this.started=false}},step:function(m){var l=m-th"
"is.initialTime;if(l>=this.durationMs){this.stop();this.onStep(1);this.onDone()}e"
"lse{this.onStep(l/this.durationMs)}},onStep:function(l){},onDone:function(){}});"
"d.profiles={linear:function(l){return l},accelerate:function(l){return Math.pow("
"l,3)},\"strong-accelerate\":function(l){return Math.pow(l,5)},decelerate:function("
"l){return 1-Math.pow(1-l,3)},\"strong-decelerate\":function(l){return 1-Math.pow(1"
"-l,5)},\"accelerate-decelerate\":function(l){var m=l<=0.5?l:1-l,n=Math.pow(2*m,3)/"
"2;return l<=0.5?n:1-n},\"strong-accelerate-decelerate\":function(l){var m=l<=0.5?l"
":1-l,n=Math.pow(2*m,5)/2;return l<=0.5?n:1-n},\"decelerate-accelerate\":function(l"
"){var m=l<=0.5?l:1-l,n=(1-Math.pow(1-2*m,2))/2;return l<=0.5?n:1-n},\"strong-dece"
"lerate-accelerate\":function(l){var m=l<=0.5?l:1-l,n=(1-Math.pow(1-2*m,3))/2;retu"
"rn l<=0.5?n:1-n},\"immediate-beginning\":function(l){return 1},\"immediate-end\":fun"
"ction(l){return l===1?1:0},\"immediate-middle\":function(l){return l>=0.5?1:0}}});"
"namespace(this,\"sozi.display\",function(c,g){var f=\"http://www.w3.org/2000/svg\";v"
"ar b=\"http://www.w3.org/1999/xlink\";var i=g.document;var k;var h;var j;c.viewPor"
"ts={};var e;c.CameraState=sozi.proto.Object.subtype({construct:function(){this.c"
"x=this.cy=0;this.width=this.height=1;this.angle=0;this.clipped=true;this.transit"
"ionZoomPercent=0;this.transitionProfile=sozi.animation.profiles.linear;this.tran"
"sitionPath=null},setCenter:function(l,m){this.cx=l;this.cy=m;return this},setSiz"
"e:function(m,l){this.width=m;this.height=l;return this},setClipped:function(l){t"
"his.clipped=l;return this},setAngle:function(l){this.angle=(l+180)%360-180;retur"
"n this},setRawAngle:function(l){this.angle=l;return this},setTransitionZoomPerce"
"nt:function(l){this.transitionZoomPercent=l;return this},setTransitionProfile:fu"
"nction(l){this.transitionProfile=l;return this},setTransitionPath:function(l){th"
"is.transitionPath=l;return this},setAtElement:function(p){var s,o,t,m;if(p.nodeN"
"ame===\"rect\"){s=p.x.baseVal.value;o=p.y.baseVal.value;t=p.width.baseVal.value;m="
"p.height.baseVal.value}else{var q=p.getBBox();s=q.x;o=q.y;t=q.width;m=q.height}v"
"ar n=i.documentElement.createSVGPoint();n.x=s+t/2;n.y=o+m/2;var r=p.getCTM();n=n"
".matrixTransform(r);var l=Math.sqrt(r.a*r.a+r.b*r.b);return this.setCenter(n.x,n"
".y).setSize(t*l,m*l).setAngle(Math.atan2(r.b,r.a)*180/Math.PI)},setAtState:funct"
"ion(l){return this.setCenter(l.cx,l.cy).setSize(l.width,l.height).setAngle(l.ang"
"le).setClipped(l.clipped).setTransitionZoomPercent(l.transitionZoomPercent).setT"
"ransitionProfile(l.transitionProfile).setTransitionPath(l.transitionPath)},inter"
"polatableAttributes:[\"width\",\"height\",\"angle\"],interpolate:function(n,o,t,v,r){v"
"ar p=1-t;for(var q=0;q<this.interpolatableAttributes.length;q+=1){var s=this.int"
"erpolatableAttributes[q];this[s]=o[s]*t+n[s]*p}var l=r?n.transitionPath:o.transi"
"tionPath;if(v&&l){var x=l.getTotalLength();if(r){var m=l.getPointAtLength(x);var"
" u=l.getPointAtLength(0);var w=l.getPointAtLength(x*p)}else{var m=l.getPointAtLe"
"ngth(0);var u=l.getPointAtLength(x);var w=l.getPointAtLength(x*t)}this.cx=w.x+(o"
".cx-u.x)*t+(n.cx-m.x)*p;this.cy=w.y+(o.cy-u.y)*t+(n.cy-m.y)*p}else{this.cx=o.cx*"
"t+n.cx*p;this.cy=o.cy*t+n.cy*p}}});c.Camera=c.CameraState.subtype({construct:fun"
"ction(n,o){c.CameraState.construct.call(this);this.viewPort=n;this.svgClipRect=i"
".createElementNS(f,\"rect\");var m=i.createElementNS(f,\"clipPath\");m.setAttribute("
"\"id\",\"sozi-clip-path-\"+n.id+\"-\"+o);m.appendChild(this.svgClipRect);n.svgGroup.ap"
"pendChild(m);var l=i.createElementNS(f,\"g\");l.setAttribute(\"clip-path\",\"url(#soz"
"i-clip-path-\"+n.id+\"-\"+o+\")\");n.svgGroup.appendChild(l);if(n.isPrimary){this.svg"
"Layer=i.createElementNS(f,\"g\");this.svgLayer.appendChild(i.getElementById(o))}el"
"se{this.svgLayer=i.createElementNS(f,\"use\");this.svgLayer.setAttributeNS(b,\"href"
"\",\"#\"+o)}l.appendChild(this.svgLayer)},setAtState:function(l){return c.CameraSta"
"te.setAtState.call(this,l).update()},getScale:function(){return Math.min(this.vi"
"ewPort.width/this.width,this.viewPort.height/this.height)},rotate:function(l){re"
"turn this.setAngle(this.angle+l).update()},zoom:function(m,l,n){return this.setS"
"ize(this.width/m,this.height/m).drag((1-m)*(l-this.viewPort.width/2),(1-m)*(n-th"
"is.viewPort.height/2))},drag:function(m,l){var q=this.getScale();var o=this.angl"
"e*Math.PI/180;var n=Math.sin(o);var p=Math.cos(o);return this.setCenter(this.cx-"
"(m*p-l*n)/q,this.cy-(m*n+l*p)/q).setClipped(false).update()},update:function(){v"
"ar q=this.getScale();var n=this.width*q;var m=this.height*q;var l=(this.viewPort"
".width-n)/2;var r=(this.viewPort.height-m)/2;this.svgClipRect.setAttribute(\"x\",t"
"his.clipped?l:0);this.svgClipRect.setAttribute(\"y\",this.clipped?r:0);this.svgCli"
"pRect.setAttribute(\"width\",this.clipped?n:this.viewPort.width);this.svgClipRect."
"setAttribute(\"height\",this.clipped?m:this.viewPort.height);var p=-this.cx+this.w"
"idth/2+l/q;var o=-this.cy+this.height/2+r/q;this.svgLayer.setAttribute(\"transfor"
"m\",\"scale(\"+q+\")translate(\"+p+\",\"+o+\")rotate(\"+(-this.angle)+\",\"+this.cx+\",\"+thi"
"s.cy+\")\");return this}});c.ViewPort=sozi.proto.Object.subtype({construct:functio"
"n(n,m,l){this.id=n;c.viewPorts[n]=this;this.isPrimary=!!l;if(this.isPrimary){if("
"e){throw\"Failed to create a primary viewport. A primary viewport already exists."
"\"}else{e=this}}this.svgGroup=i.createElementNS(f,\"g\");this.svgGroup.setAttribute"
"(\"class\",\"sozi-viewport\");this.svgGroup.setAttribute(\"id\",\"sozi-viewport-\"+n);i."
"documentElement.appendChild(this.svgGroup);this.setLocation(0,0).setSize(g.inner"
"Width,g.innerHeight);this.cameras={};m.forEach(function(o){this.cameras[o]=c.Cam"
"era.instance(this,o)},this)},setSize:function(m,l){this.width=m;this.height=l;re"
"turn this},setLocation:function(l,m){this.x=l;this.y=m;return this},contains:fun"
"ction(l,m){return l>=this.x&&l<this.x+this.width&&m>=this.y&&m<this.y+this.heigh"
"t},getDocumentState:function(){var m=c.CameraState.instance().setCenter(k.x+k.wi"
"dth/2,k.y+k.height/2).setSize(k.width,k.height).setClipped(false);var l={};for(v"
"ar n in this.cameras){l[n]=m}return l},update:function(){this.svgGroup.setAttrib"
"ute(\"transform\",\"translate(\"+this.x+\",\"+this.y+\")\");for(var l in this.cameras){t"
"his.cameras[l].update()}return this},showFrame:function(l){for(var m in l.states"
"){this.cameras[m].setAtState(l.states[m])}return this},drag:function(m,l){for(va"
"r n in this.cameras){this.cameras[n].drag(m,l)}return this},zoom:function(m,l,o)"
"{for(var n in this.cameras){this.cameras[n].zoom(m,l,o)}return this},rotate:func"
"tion(l){for(var m in this.cameras){this.cameras[m].rotate(l)}return this},onWind"
"owResize:function(m,l){this.setLocation(this.x*m,this.y*l).setSize(this.width*m,"
"this.height*l).update()}});function d(){var l=i.documentElement;k=l.getBBox();h="
"g.innerWidth;j=g.innerHeight;l.setAttribute(\"width\",h);l.setAttribute(\"height\",j"
");sozi.events.fire(\"sozi.display.ready\")}function a(){var l=i.documentElement;l."
"setAttribute(\"width\",g.innerWidth);l.setAttribute(\"height\",g.innerHeight);for(va"
"r m in c.viewPorts){c.viewPorts[m].onWindowResize(g.innerWidth/h,g.innerHeight/j"
")}h=g.innerWidth;j=g.innerHeight}sozi.events.listen(\"sozi.document.ready\",d);g.a"
"ddEventListener(\"resize\",a,false)});namespace(this,\"sozi.document\",function(c,e)"
"{var g=e.document;var b=\"http://sozi.baierouge.fr\";var d={title:\"Untitled\",seque"
"nce:\"0\",hide:\"true\",clip:\"true\",\"show-in-frame-list\":\"true\",\"timeout-enable\":\"fa"
"lse\",\"timeout-ms\":\"5000\",\"transition-duration-ms\":\"1000\",\"transition-zoom-percen"
"t\":\"0\",\"transition-profile\":\"linear\",\"transition-path-hide\":\"true\"};var h=[\"g\",\""
"image\",\"path\",\"rect\",\"circle\",\"ellipse\",\"line\",\"polyline\",\"polygon\",\"text\",\"clip"
"path\"];c.frames=[];c.idLayerList=[];function j(l,k){return l.getAttributeNS(b,k)"
"||d[k]}function i(o,p,k){var l=o.states[p]=o.states[p]||sozi.display.CameraState"
".instance();if(typeof l.transitionZoomPercent===\"undefined\"||k.hasAttributeNS(b,"
"\"transition-zoom-percent\")){l.setTransitionZoomPercent(parseInt(j(k,\"transition-"
"zoom-percent\"),10))}if(typeof l.transitionProfile===\"undefined\"||k.hasAttributeN"
"S(b,\"transition-profile\")){l.setTransitionProfile(sozi.animation.profiles[j(k,\"t"
"ransition-profile\")])}if(typeof l.transitionPath===\"undefined\"||k.hasAttributeNS"
"(b,\"transition-path\")){var n=g.getElementById(k.getAttributeNS(b,\"transition-pat"
"h\"));if(n&&n.nodeName===\"path\"){l.setTransitionPath(n);if(j(k,\"transition-path-h"
"ide\")===\"true\"){n.style.visibility=\"hidden\"}}}if(k.hasAttributeNS(b,\"refid\")){va"
"r m=g.getElementById(k.getAttributeNS(b,\"refid\"));if(m){l.setAtElement(m);if(j(k"
",\"hide\")===\"true\"){m.style.visibility=\"hidden\"}}}if(k.hasAttributeNS(b,\"clip\")){"
"l.setClipped(j(k,\"clip\")===\"true\")}}function a(){var l=[];var p=g.getElementsByT"
"agNameNS(b,\"layer\");for(var n=0;n<p.length;n+=1){var s=p[n].getAttributeNS(b,\"gr"
"oup\");if(s&&l.indexOf(s)===-1){l.push(s)}}var r=g.documentElement;var o=\"http://"
"www.w3.org/2000/svg\";var q=g.createElementNS(o,\"g\");var k=Array.prototype.slice."
"call(r.childNodes);k.forEach(function(u,t){if(!u.getAttribute){r.removeChild(u)}"
"else{if(l.indexOf(u.getAttribute(\"id\"))!==-1){if(q.firstChild){q.setAttribute(\"i"
"d\",\"sozi-wrapper-\"+t);c.idLayerList.push(\"sozi-wrapper-\"+t);r.insertBefore(q,u);"
"q=g.createElementNS(o,\"g\")}c.idLayerList.push(u.getAttribute(\"id\"))}else{if(h.in"
"dexOf(u.localName.toLowerCase())!==-1){r.removeChild(u);q.appendChild(u)}}}});if"
"(q.firstChild){q.setAttribute(\"id\",\"sozi-wrapper-\"+k.length);c.idLayerList.push("
"\"sozi-wrapper-\"+k.length);r.appendChild(q)}var m=Array.prototype.slice.call(g.ge"
"tElementsByTagNameNS(b,\"frame\"));m.sort(function(u,t){var w=parseInt(j(u,\"sequen"
"ce\"),10);var v=parseInt(j(t,\"sequence\"),10);return w-v});m.forEach(function(v,u)"
"{var x={id:v.getAttribute(\"id\"),title:j(v,\"title\"),showInFrameList:j(v,\"show-in-"
"frame-list\")===\"true\",sequence:parseInt(j(v,\"sequence\"),10),timeoutEnable:j(v,\"t"
"imeout-enable\")===\"true\",timeoutMs:parseInt(j(v,\"timeout-ms\"),10),transitionDura"
"tionMs:parseInt(j(v,\"transition-duration-ms\"),10),states:{}};c.idLayerList.forEa"
"ch(function(A){if(u===0||A.search(\"sozi-wrapper-[0-9]+\")!==-1){i(x,A,v)}else{var"
" z=x.states[A]=sozi.display.CameraState.instance();var y=c.frames[c.frames.lengt"
"h-1].states[A];z.setAtState(y)}});var t=Array.prototype.slice.call(v.getElements"
"ByTagNameNS(b,\"layer\"));t.forEach(function(y){var z=y.getAttributeNS(b,\"group\");"
"if(z&&c.idLayerList.indexOf(z)!==-1){i(x,z,y)}});for(var w in x.states){if(x.sta"
"tes.hasOwnProperty(w)){c.frames.push(x);break}}})}c.getFrameIndexForId=function("
"l){for(var k=0;k<c.frames.length;k+=1){if(c.frames[k].id===l){return k}}return -"
"1};function f(){g.documentElement.removeAttribute(\"viewBox\");a();sozi.events.fir"
"e(\"sozi.document.ready\")}e.addEventListener(\"load\",f,false)});namespace(this,\"so"
"zi.framelist\",function(u,k){var o=k.document;var c=5;var i;var p;var j=0;var h;v"
"ar s;var b;var v;var w;var t;var e=300;var f=\"decelerate\";var a=\"http://www.w3.o"
"rg/2000/svg\";function n(z){var x=z.relatedTarget,y=o.documentElement;while(x&&x!"
"==i&&x!==y){x=x.parentNode}if(x!==i){u.hide();sozi.player.restart();z.stopPropag"
"ation()}}function r(y){var x=p.getCTM().f;if(x<=-k.innerHeight/2){x+=k.innerHeig"
"ht/2}else{if(x<0){x=0}}p.setAttribute(\"transform\",\"translate(0,\"+x+\")\");y.stopPr"
"opagation()}function d(y){var x=p.getCTM().f;if(x+j>=k.innerHeight*3/2){x-=k.inn"
"erHeight/2}else{if(x+j>k.innerHeight+2*c){x=k.innerHeight-j-4*c}}p.setAttribute("
"\"transform\",\"translate(0,\"+x+\")\");y.stopPropagation()}function g(x){return funct"
"ion(y){sozi.player.previewFrame(x);y.stopPropagation()}}function l(x){x.stopProp"
"agation()}function q(){i=o.createElementNS(a,\"g\");i.setAttribute(\"id\",\"sozi-toc\""
");o.documentElement.appendChild(i);p=o.createElementNS(a,\"g\");i.appendChild(p);v"
"ar y=o.createElementNS(a,\"rect\");y.setAttribute(\"id\",\"sozi-toc-background\");y.se"
"tAttribute(\"x\",c);y.setAttribute(\"y\",c);y.setAttribute(\"rx\",c);y.setAttribute(\"r"
"y\",c);y.addEventListener(\"click\",l,false);y.addEventListener(\"mousedown\",l,false"
");y.addEventListener(\"mouseout\",n,false);p.appendChild(y);var A=0;sozi.document."
"frames.forEach(function(D,E){if(D.showInFrameList){var C=o.createElementNS(a,\"te"
"xt\");C.appendChild(o.createTextNode(D.title));C.setAttribute(\"id\",\"sozi-toc-\"+D."
"id);p.appendChild(C);if(E===sozi.player.currentFrameIndex){C.setAttribute(\"class"
"\",\"sozi-toc-current\")}var B=C.getBBox().width;j+=C.getBBox().height;if(B>A){A=B}"
"C.setAttribute(\"x\",2*c);C.setAttribute(\"y\",j+c);C.addEventListener(\"click\",g(E),"
"false);C.addEventListener(\"mousedown\",l,false)}});var x=o.createElementNS(a,\"pat"
"h\");x.setAttribute(\"class\",\"sozi-toc-arrow\");x.setAttribute(\"d\",\"M\"+(A+3*c)+\",\"+"
"(5*c)+\" l\"+(4*c)+\",0 l-\"+(2*c)+\",-\"+(3*c)+\" z\");x.addEventListener(\"click\",r,fal"
"se);x.addEventListener(\"mousedown\",l,false);i.appendChild(x);var z=o.createEleme"
"ntNS(a,\"path\");z.setAttribute(\"class\",\"sozi-toc-arrow\");z.setAttribute(\"d\",\"M\"+("
"A+3*c)+\",\"+(7*c)+\" l\"+(4*c)+\",0 l-\"+(2*c)+\",\"+(3*c)+\" z\");z.addEventListener(\"cl"
"ick\",d,false);z.addEventListener(\"mousedown\",l,false);i.appendChild(z);y.setAttr"
"ibute(\"width\",A+7*c);y.setAttribute(\"height\",j+2*c);h=-A-9*c;s=0;w=v=h;i.setAttr"
"ibute(\"transform\",\"translate(\"+h+\",0)\");t=sozi.animation.Animator.instance().aug"
"ment({onStep:function(B){var D=sozi.animation.profiles[f](B),C=1-D;w=v*D+b*C;i.s"
"etAttribute(\"transform\",\"translate(\"+w+\",0)\")}})}function m(x){var y=Array.proto"
"type.slice.call(o.getElementsByClassName(\"sozi-toc-current\"));y.forEach(function"
"(A){A.removeAttribute(\"class\")});var z=sozi.document.frames[x];if(z.showInFrameL"
"ist){o.getElementById(\"sozi-toc-\"+z.id).setAttribute(\"class\",\"sozi-toc-current\")"
"}}u.show=function(){o.documentElement.appendChild(i);b=w;v=s;t.start(e)};u.hide="
"function(){b=w;v=h;t.start(e)};u.isVisible=function(){return v===s};sozi.events."
"listen(\"sozi.player.ready\",q);sozi.events.listen(\"sozi.player.cleanup\",u.hide);s"
"ozi.events.listen(\"sozi.player.framechange\",m)});namespace(this,\"sozi.framenumbe"
"r\",function(a,d){var g=d.document;var e;var k,i;var f;var b=\"http://www.w3.org/2"
"000/svg\";function h(){var m=k.getBBox(),n=Math.max(m.width,m.height)*0.75,l=n*1."
"25;f.setAttribute(\"r\",n);e.setAttribute(\"transform\",\"translate(\"+l+\",\"+l+\")\")}fu"
"nction c(){e=g.createElementNS(b,\"g\");k=g.createElementNS(b,\"text\");f=g.createEl"
"ementNS(b,\"circle\");e.setAttribute(\"id\",\"sozi-framenumber\");f.setAttribute(\"cx\","
"0);f.setAttribute(\"cy\",0);e.appendChild(f);i=g.createTextNode(sozi.player.curren"
"tFrameIndex+1);k.setAttribute(\"text-anchor\",\"middle\");k.setAttribute(\"dominant-b"
"aseline\",\"central\");k.setAttribute(\"x\",0);k.setAttribute(\"y\",0);k.appendChild(i)"
";e.appendChild(k);g.documentElement.appendChild(e);h()}function j(l){i.nodeValue"
"=l+1}sozi.events.listen(\"sozi.player.ready\",c);sozi.events.listen(\"sozi.player.f"
"ramechange\",j)});namespace(this,\"sozi.links\",function(c,e){var b=\"http://www.w3."
"org/2000/svg\";var a=\"http://www.w3.org/1999/xlink\";function f(g){return function"
"(h){sozi.player.moveToFrame(g);h.preventDefault();h.stopPropagation()}}function "
"d(){var h=e.document.getElementsByTagNameNS(b,\"a\");for(var j=0;j<h.length;j+=1){"
"var g=h[j].getAttributeNS(a,\"href\");if(g&&g[0]===\"#\"){h[j].addEventListener(\"cli"
"ck\",f(sozi.location.getFrameIndexForHash(g)),false)}}}sozi.events.listen(\"sozi.d"
"ocument.ready\",d)});namespace(this,\"sozi.location\",function(a,d){var b=false;a.g"
"etFrameIndex=function(){return a.getFrameIndexForHash(d.location.hash)};a.getFra"
"meIndexForHash=function(g){var h=g?g.slice(1):\"1\";var f;if(/^[0-9]+$/.test(h)){f"
"=parseInt(h,10)-1}else{f=sozi.document.getFrameIndexForId(h)}if(f<0){return 0}el"
"se{if(f>=sozi.document.frames.length){return sozi.document.frames.length-1}else{"
"return f}}};function e(){var f=a.getFrameIndex();if(!b){sozi.player.moveToFrame("
"f)}b=false}function c(f){b=true;d.location.hash=\"#\"+sozi.document.frames[f].id}d"
".addEventListener(\"hashchange\",e,false);sozi.events.listen(\"sozi.player.framecha"
"nge\",c)});namespace(this,\"sozi.player\",function(d,g){var l;var c;var i;var e=500"
";var n=-10;var j=\"linear\";var f=0;d.currentFrameIndex=0;var k=false;var m=false;"
"function h(){if(sozi.document.frames[d.currentFrameIndex].timeoutEnable){m=true;"
"var o=(d.currentFrameIndex+1)%sozi.document.frames.length;i=g.setTimeout(functio"
"n(){d.moveToFrame(o)},sozi.document.frames[d.currentFrameIndex].timeoutMs)}}d.st"
"artFromIndex=function(o){k=true;m=false;f=o;d.currentFrameIndex=o;l.showFrame(so"
"zi.document.frames[o]);h()};d.restart=function(){d.startFromIndex(d.currentFrame"
"Index)};d.stop=function(){c.stop();if(m){g.clearTimeout(i);m=false}k=false;f=d.c"
"urrentFrameIndex};function b(o,y,w){var z={ss:((o<0)?Math.max(y,w):Math.min(y,w)"
")*(100-o)/100,ts:0.5,k:0};if(o!==0){var s=y-w;var r=y-z.ss;var q=w-z.ss;if(s!==0"
"){var p=Math.sqrt(r*q);var x=(r-p)/s;var t=(r+p)/s;z.ts=(x>0&&x<=1)?x:t}z.k=r/z."
"ts/z.ts}return z}d.jumpToFrame=function(o){d.stop();sozi.events.fire(\"sozi.playe"
"r.cleanup\");f=o;d.currentFrameIndex=o;l.showFrame(sozi.document.frames[o]);sozi."
"events.fire(\"sozi.player.framechange\",o)};d.getAnimationData=function(o,q,s,p,v,"
"t){var r={};for(var w in o){r[w]={initialState:sozi.display.CameraState.instance"
"(),finalState:sozi.display.CameraState.instance(),useTransitionPath:v,reverseTra"
"nsitionPath:t};r[w].profile=p||q[w].transitionProfile;r[w].initialState.setAtSta"
"te(o[w]);if(q.hasOwnProperty(w)){r[w].finalState.setAtState(q[w])}else{r[w].fina"
"lState.setAtState(o[w])}if(r[w].finalState.angle-r[w].initialState.angle>180){r["
"w].finalState.setRawAngle(r[w].finalState.angle-360)}else{if(r[w].finalState.ang"
"le-r[w].initialState.angle<-180){r[w].initialState.setRawAngle(r[w].initialState"
".angle-360)}}var u=s||q[w].transitionZoomPercent;if(u&&q.hasOwnProperty(w)){r[w]"
".zoomWidth=b(u,o[w].width,q[w].width);r[w].zoomHeight=b(u,o[w].height,q[w].heigh"
"t)}}return r};d.previewFrame=function(o){d.currentFrameIndex=o;c.start(e,d.getAn"
"imationData(l.cameras,sozi.document.frames[o].states,n,sozi.animation.profiles[j"
"]),false,false);sozi.events.fire(\"sozi.player.framechange\",o)};d.moveToFrame=fun"
"ction(r){if(m){g.clearTimeout(i);m=false}var q,t,s,p,o;if(r===(d.currentFrameInd"
"ex-1)%sozi.document.frames.length){q=sozi.document.frames[d.currentFrameIndex].t"
"ransitionDurationMs;t=undefined;s=undefined;p=true;o=true}else{if(r===(d.current"
"FrameIndex+1)%sozi.document.frames.length){q=sozi.document.frames[r].transitionD"
"urationMs;t=undefined;s=undefined;p=true;o=false}else{q=e;t=n;s=sozi.animation.p"
"rofiles[j];p=false;o=false}}sozi.events.fire(\"sozi.player.cleanup\");k=true;d.cur"
"rentFrameIndex=r;c.start(q,d.getAnimationData(l.cameras,sozi.document.frames[r]."
"states,t,s,p,o));sozi.events.fire(\"sozi.player.framechange\",r)};d.jumpToFirst=fu"
"nction(){d.jumpToFrame(0)};d.moveToFirst=function(){d.moveToFrame(0)};d.jumpToPr"
"evious=function(){var o=d.currentFrameIndex;if(!c.started||f<=d.currentFrameInde"
"x){o-=1}if(o>=0){d.jumpToFrame(o)}};d.moveToPrevious=function(){for(var o=d.curr"
"entFrameIndex-1;o>=0;o-=1){var p=sozi.document.frames[o];if(!p.timeoutEnable||p."
"timeoutMs!==0){d.moveToFrame(o);break}}};d.jumpToNext=function(){var o=d.current"
"FrameIndex;if(!c.started||f>=d.currentFrameIndex){o+=1}if(o<sozi.document.frames"
".length){d.jumpToFrame(o)}};d.moveToNext=function(){if(d.currentFrameIndex<sozi."
"document.frames.length-1||sozi.document.frames[d.currentFrameIndex].timeoutEnabl"
"e){d.moveToFrame((d.currentFrameIndex+1)%sozi.document.frames.length)}};d.jumpTo"
"Last=function(){d.jumpToFrame(sozi.document.frames.length-1)};d.moveToLast=funct"
"ion(){d.moveToFrame(sozi.document.frames.length-1)};d.moveToCurrent=function(){d"
".moveToFrame(d.currentFrameIndex)};d.showAll=function(){d.stop();sozi.events.fir"
"e(\"sozi.player.cleanup\");c.start(e,d.getAnimationData(l.cameras,l.getDocumentSta"
"te(),n,sozi.animation.profiles[j],false,false))};function a(){l=sozi.display.Vie"
"wPort.instance(\"player\",sozi.document.idLayerList,true);d.startFromIndex(sozi.lo"
"cation.getFrameIndex());g.setTimeout(l.bind(l.update),1);sozi.events.fire(\"sozi."
"player.ready\")}d.onAnimationStep=function(o,q){for(var s in q){var p=l.cameras[s"
"];p.interpolate(q[s].initialState,q[s].finalState,q[s].profile(o),q[s].useTransi"
"tionPath,q[s].reverseTransitionPath);var r;if(q[s].zoomWidth&&q[s].zoomWidth.k!="
"=0){r=o-q[s].zoomWidth.ts;p.width=q[s].zoomWidth.k*r*r+q[s].zoomWidth.ss}if(q[s]"
".zoomHeight&&q[s].zoomHeight.k!==0){r=o-q[s].zoomHeight.ts;p.height=q[s].zoomHei"
"ght.k*r*r+q[s].zoomHeight.ss}p.setClipped(q[s].finalState.clipped)}l.update()};c"
"=sozi.animation.Animator.instance().augment({onStep:function(o){d.onAnimationSte"
"p(o,this.data)},onDone:function(){for(var o in this.data){l.cameras[o].setAtStat"
"e(this.data[o].finalState)}l.update();f=d.currentFrameIndex;if(k){h()}}});sozi.e"
"vents.listen(\"sozi.display.ready\",a)});";

static const char sozi_extras_media_min_js[] =
"this.addEventListener(\"load\",function(){var h=\"http://www.w3.org/2000/svg\",l=\"ht"
"tp://sozi.baierouge.fr\",s=\"http://www.w3.org/1999/xhtml\",m=this,o=m.document,q=["
"],r,e,d,c,p,a,g,f,b;function n(i){i.stopPropagation()}function t(i,j,k){sozi.eve"
"nts.listen(\"sozi.player.framechange\",function(u){var v=sozi.document.frames[u].i"
"d;if(v===j){i.play()}else{if(v===k){i.pause()}}})}q.push(o.getElementsByTagNameN"
"S(l,\"video\"));q.push(o.getElementsByTagNameNS(l,\"audio\"));r=[];for(c=0;c<q.lengt"
"h;c+=1){for(e=0;e<q[c].length;e+=1){p=q[c][e].parentNode;b=o.createElementNS(s,\""
"source\");b.setAttribute(\"type\",q[c][e].getAttributeNS(l,\"type\"));b.setAttribute("
"\"src\",q[c][e].getAttributeNS(l,\"src\"));for(d=0;d<r.length;d+=1){if(r[d].rect===p"
"){break}}if(d===r.length){p.setAttribute(\"visibility\",\"hidden\");f=o.createElemen"
"tNS(s,q[c][e].localName);f.setAttribute(\"controls\",\"controls\");if(q[c][e].localN"
"ame===\"video\"){f.setAttribute(\"width\",p.getAttribute(\"width\"));f.setAttribute(\"h"
"eight\",p.getAttribute(\"height\"))}f.addEventListener(\"click\",n,false);f.addEventL"
"istener(\"contextmenu\",n,false);g=o.createElementNS(s,\"html\");g.appendChild(f);a="
"o.createElementNS(h,\"foreignObject\");a.setAttribute(\"x\",p.getAttribute(\"x\"));a.s"
"etAttribute(\"y\",p.getAttribute(\"y\"));a.setAttribute(\"width\",p.getAttribute(\"widt"
"h\"));a.setAttribute(\"height\",p.getAttribute(\"height\"));a.appendChild(g);p.parent"
"Node.insertBefore(a,p.nextSibling);if(q[c][e].hasAttributeNS(l,\"start-frame\")){t"
"(f,q[c][e].getAttributeNS(l,\"start-frame\"),q[c][e].getAttributeNS(l,\"stop-frame\""
"))}r.push({rect:q[c][e].parentNode,htmlMedia:f})}r[d].htmlMedia.appendChild(b)}}"
"},false);";

static const char sozi_min_css[] =
"#sozi-toc text{fill:#eff;font-family:Verdana,sans-serif;font-size:12pt}#sozi-toc"
" text:hover{fill:#0cf;cursor:pointer}#sozi-toc text.sozi-toc-current{fill:#fa4}#"
"sozi-toc-background{stroke:#222;stroke-opacity:.1;stroke-width:10;fill:#222;fill"
"-opacity:.9}.sozi-toc-arrow{fill:#eff;fill-opacity:.75;stroke:none}.sozi-toc-arr"
"ow:hover{fill:#0cf}#sozi-framenumber circle{stroke:#222;stroke-opacity:.1;stroke"
"-width:4;fill:#222;fill-opacity:.9}#sozi-framenumber text{fill:#eff;font-family:"
"Verdana,sans-serif;font-size:12pt}";

static const char sozi_version[] =
"14.09-13143300";

#endif /* SOZI_PLAYER_H */