SQLite format 3   @    �                                                             � -�   � zA�                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  C_indexFilenameBrowseCREATE INDEX Filename ON Browse(Filename)4KindexTagBrowseCREATE INDEX Tag ON Browse(Tag)7OindexNameBrowseCREATE INDEX Name ON Browse(Name)��atableBrowseBrowseCREATE TABLE Browse (Kind INTEGER,Name TEXT,Tag TEXT,Filename TEXT,Lineno INTEGER,Text TEXT,Extra INTEGER)   �    ������������+Ji����$Dw��� F   �=#
window_namesys.c%� )runningmain.cbool running = �%argvmain.cchar **argv)�argcmain.cint argc,3�	Mmainmain.cint main(int argc, char **argv){�#vidmain.c	vid_t vid =�vid_initmain.c
�#sysmain.csys_t sys =�sys_initmain.c�!sys_updatemain.c�	%sys_shutdownmain.c�
%vid_shutdownmain.c�hwsys_ssys.hHWND hw;�sys_ssys.h�sys_tsys_ssys.h�'
vid_default_wvid.h�'
vid_default_hvid.h�
vid_bppvid.h$�'bmpvid_svid.h	uint8_t *bmp;"�'hvid_svid.huint16_t w,h; �#wvid_svid.huint16_t w,�vid_svid.h�vid_tvid_svid.h
�7#vidvid.cvid_t *vid)0�8	Avid_initvid.cvoid vid_init(vid_t *vid){�9mallocvid.c	�:#vidvid.cvid_t *vid)8�;	%� �=   �.   �f   �   �F   �   �d   �G   �y   �{   �,   �� �   �����yfP?5+"�������������wk_VJA8/ ��������we\SJA8 �+ � � � � � � � �       vid7wp"w
vid_t%vid_shutdown	%vid_shutdown	A
vid_svid_init�vid_init	>'vid_default_w'vid_default_hvid_bppvid3vid)vid�vid	@vid	=%timer_update!timer_init
timer!sys_update+!sys_update
sys_t+sys_swapbuffers5+sys_swapbuffers%sys_shutdown
sys_ssys_proc%sys_initsys_errorsys4sys*sys strcatrec1real_wreal_hmsg,msg#malloc	?	main�lp!hw$hwhgflags0gflags'gflags&gflags�	free	B	exit error_strdcbmpbmi	argv�	argc�#WINDOW_NAME-TranslateMessage.'StretchDIBits6
Sleep� 7   'WebPDecodeBGR7�   'tex_load_webp7��� � b7j� �� 	argc7>�   	lp7�         fp!Q   �    �������������������|vpjd^XRLF@:4.("
����������������������ztnhb\VPJD>82,&����������������  ����vk`UJ �?4)     r
tex_so
vid_s
vid_s
vid_s
vid_s
vid_s
vid_s
tex_sm
tex_sl
tex_sk
tex_sj
sys_s
sys_s
sys_s
sys_snihgfedcba`_^]\[ZYXWqpRQPONMLKJIHGFEDCBA@?>=<;:9876543210/.-,+*)('&%$#"! 
	   7__pobr_tag_te   8   7�   �    ��Uamy�������������������ti^SH=2'��� � � � � � � � �$/:EP[fq|������������  
s
sys.c?
sys.c>
sys.c=
sys.c<
sys.c;
sys.c:
sys.c9
sys.c8
sys.c7
sys.c6
sys.c5main.c�main.c�main.c�main.c�main.c�main.c�main.c main.cmain.cmain.cmain.cmain.cmain.cmain.cmain.cmain.c	
sys.c4
sys.c3
sys.c2
sys.c1
sys.c0
sys.c/
sys.c.
sys.c-
sys.c,
sys.c+
sys.c*
sys.c)
sys.c(
sys.c'
sys.c&
sys.c%
sys.c$
sys.c#
sys.c"
sys.c!
sys.c 
sys.c
sys.c
sys.c
sys.c
sys.c
sys.h

sys.h
sys.h
sys.h
sys.h
sys.h
sys.h
vid.c	=
vid.c	>
vid.c	?
vid.c	@
vid.c	A
vid.c	B
vid.h
vid.h
vid.h
vid.h
vid.h
vid   0main.c6�   timer.c7�   

sys.c7�    $U�����9U������������������        !    � )-g   4-min_tsteptimer_stimer.hfloat min_tstep;   ,%tsteptimer_stimer.hfloat tstep;   *#freqtimer_stimer.hfloat freq;   2+new_timetimer_stimer.hfloat new_time;   2+old_timetimer_stimer.hfloat old_time;   @#Anew_time_64timer_stimer.hLARGE_INTEGER new_time_64;   @#Aold_time_64timer_stimer.h
LARGE_INTEGER old_time_64;   timer_stimer.h   "timer_ttimer_stimer.h�#
WINDOW_NAMEsys.c.�	9error_strsys.cconst char *error_str)=�
	Ysys_errorsys.cvoid sys_error(const char *error_str){�!MessageBoxsys.c	�strcatsys.c	�exitsys.c
�!lpsys.cLPARAM lp)�!wpsys.cWPARAM wp,�msgsys.cUINT msg,�hwsys.cHWND hw,Z�		�sys_procsys.cLRESULT CALLBACK sys_proc(HWND hw, UINT msg, WPARAM wp, LPARAM lp){$�+gflagssys.cuint8_t gflags;$�+gflagssys.cuint8_t gflags;    x  x � � � �Pn����3Ss���]����������
GF$�&-x_maxvid.c
uint16_t x_max =&�'�'DefWindowProcsys.c#�+timersys.c#timer_t *timer)�#vidsys.c#vid_t *vid,�#syssys.c#sys_t *sys,P�	!}sys_updatesys.c#void sys_update(sys_t *sys, vid_t *vid, timer_t *timer){�msgsys.c%MSG msg =�#PeekMessagesys.c'�-TranslateMessagesys.c(�+DispatchMessagesys.c)$�+gflagssys.c,uint8_t gflags;�!recsys.c0RECT rec =� 'GetClientRectsys.c1�!#vidsys.c<vid_t *vid)�"#syssys.c<sys_t *sys,I�#	+esys_swapbufferssys.c<void sys_swapbuffers(sys_t *sys,vid_t *vid){�$'StretchDIBitssys.c=�%#vidsys.cBvid_t *vid)�&#syssys.cBsys_t *sys,<�'	Ysys_initsys.cBvoid sys_init(sys_t *sys, vid_t *vid){%�(/hinstsys.cDHINSTANCE hinst =�)+GetModuleHandlesys.cF�*sys_errorsys.cG �++wcsys.cJWNDCLASSEX wc =�,!LoadCursorsys.cN
 �  �2> a� �`��o2g���
Rt" ��w�S��@#��� ��>>I �;;�����;���������c&�)CreateWindowEx&J' � + � 'Des  7DestroyWindow/]   "DestroyWindow2  ReleaseDC2: 	argc7
Sleep8H#GF_MAINLOOP8P'DefWindowProc7�!MessageBox7�#WINDOW_NAME7����� I'VID_DEFAULT_W8�VID_BPP8�GF_RESIZE8Q+GetModuleHandle7�'StretchDIBits7�'GetClientRect7�+DispatchMessage7�-TranslateMessage7�#PeekMessage7�- b7j;QueryPerformanceCounter7�?QueryPerformanceFrequency7���� b.eg� � )CreateWindowEx7�+RegisterClassEx7�!LoadCursor7�TIMER_CPS8n��� � 
GetDC7�
�� � � 'bmp2� � __pobr_tag_tex_h_00028kVID_BPP8�'VID_DEFAULT_H8�;  9F -_ __pobr_taF __pobr_tag_tex_h_00018l!ShowWindow7�)GetStartupInfo7�� __pobr_tag_tex_h_00018*'DestroyWindow7�ReleaseDC7�� I__pobr_tag_vid_h_00038:� __pobr_tag_vid_h_000489� WebPDecodeBGR7�       DestroyWindow6z;QueryPerformanceCounter7�
 < �'���o@&
���"� � �N ��QBw�L�^T��o�8.������`p�+w�U'�C��7�0�ttt������	free!�	memcpy&�filename&j
fo printf+� � 
free)�calloc7�c7�byte_w7�� 	freq8q >  	blue8�h7�	free7�	free7�	cyan8�dc8R	exit7�error_str7��fp7�	data7�data_size7�calloc7�filename7�	free7�!line_width7�bmp7�h8�hw8T!freq_query7�	free7�
fseek7�
fopen7�bmp8�gflags8<bmp8�gflags7�hw7�� h8�p c8�
green8�
ftell7�~� g8�gflags7�bmi8Sgflags7�	free8bm_off7�bmp_size7�dec_data7�height7�fclose7�
fread7�
fseek7�
hinst7�: frb8�
black8�	game8�	argv8=	info7�J co	argc8>c colcolor_t8��z � inw de7__pobr_tag_vid_h_00048�7__pobr_tag_tex_h_00018�7__pobr_tag_tex_h_00028�   __pobr_tag_vid_h_00038�7__pobr_tag_vid_h_00038�	game8K
   I �  � � � � ����������xl`TH<0$ ��'2=HS^it�����������$/:EP[fq|��������������
game.c8game.c8game.game.c8�game.c8�game.c8�game.c8�game.c8�main.c8Omain.c8Nmain.c8Mmain.c8Lmain.c8Kmain.c8Jmain.c8Imain.c8Hmain.c8Gmain.c8Fmain.c8Emain.c8Dmain.c8Cmain.c8Bmain.c8Amain.c8@main.c8?main.c8>main.c8=main.c8<
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
sys.c7�
   K �  � �/$ � �:EP[fq|����������� !,7BMXcny������������������vk`UJ?4)�� � �������

tex.h8(
tex.h8'
te
tex.h8�
tex.h8�
sys.c7�
sys.c7�
sys.h8V
sys.h8U
sys.h8T
sys.h8S
sys.h8R
sys.h8Q
sys.h8P
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.c7�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�
tex.h8�timer.c7�timer.c7�timer.c7�
   C (5�����vi\OB������'2=HS^it�����������$/:E�����������|qf[P��������=&�
tex.h8
tex.h8
tex.h8
tex.h8timer.c7�timer.c7�timer.c7�timer.c7�timer.c7�timer.c7�timer.c7�timer.c7�timer.c7�timer.h8wtimer.h8vtimer.h8utimer.h8ttimer.h8stimer.h8rtimer.h8qtimer.h8ptimer.h8otimer.h8n
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c7�
vid.c8 
vid.c8
vid.c8
vid.c8
vid.c8
vid.c8
vid.c8
vid.c8
vid.c8
vid.c8	
vid.c8

vid.c8
vid.c8
vid.c8
vid.c8
vid.c8
vid.h8�
vid.h8�
vid.h8�
vid.h8�
vid.h8�
vid.h8�
vid.h8�
vid.h8�
vid.h8�
vid.h8�
vid.h8�
vid.h8�
vid.h8�
vid.h8�
vid.h8�
vid.h8�
   4� ����������
"(.4:@FLRX^djpv|�����������������������������������������������������������������FLRX^djpv|���������������������7<7=7>7?7@7A7B7C7D7E7F7G7H7I7J7K7L7M7N7O7P7Q7U7W7X7Y7Z7[7\7]7^� 7<� 7=J 7>J 7?J 7@J 7AJ 7BJ 7CJ 7DJ 7EJ 7FJ 7GJ 7HJ 7IJ 7JJ 7KJ 7LJ 7MJ 7NJ 7OJ 7PJ 7Q� T7U� N7W   7X   7Y   7Z   7[   7\   7]   7^   7_   7`   7e   7k   7l� 7n   *7v   $7x   7y   7z   7�   7�   7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�    ��qJ    Jw�6Pn���� � � ` 9�$�,-x_maxvid.c
uint16_t x_max =$�+-x_minvid.c
uint16_t x_min =$�*-y_maxvid.c	uint16_t y_max =$�)-y_minvid.c	uint16_t y_min ='�1heighttex.cMint width, height;*�3dec_datatex.cNuint8_t *dec_data =�'WebPDecodeBGRtex.cN�freetex.cO�%tex_flip_bmptex.cQ�#vidtimer.cvid_t *vid)%�+timertimer.ctimer_t *timer,� I	!etimer_inittimer.cvoid timer_init(timer_t *timer, vid_t *vid){5�!Afreq_querytimer.cLARGE_INTEGER freq_query =*�?QueryPerformanceFrequencytimer.c
(� ;QueryPerformanceCountertimer.c%�!+timertimer.ctimer_t *timer)� A	%Qtimer_updatetimer.cvoid timer_update(timer_t *timer){(�#;QueryP*�37vec2_t__pobr_tag_vid_h_0003vid.h$�27__pobr_tag_vid_h_0003vid.h$�17__pobr_tag_vid_h_0004vid.h0�07#x__pobr_tag_vid_h_0003vid.huint16_t x,2�/7'y__pobr_tag_vid_h_0003vid.huint16_t x,y;
� R� ����������� &,28>DJPV\bhntz����������������������
"(.4:@FLRX^djpv|���������������7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�8 88888� 87�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�7�8 888888888	8
8888   T8   N8� 8� 8   <8   6__pobr_tag_tex_h_00017g   __pobr_tag_tex_h_00017h    Q ����aA%
���}bC"���{]G1 � � � Q�pU�	�3(,�G!3line_widthtex.csize_t line_width =P�F	%ytex_flip_bmptex.cvoid tex_flip_bmp(uint8_t *bmp,uint16_t w,uint16_t h){�E'bmptex.cuint8_t *bmp,�D#wtex.cuint16_t w,�C#htex.cuint16_t h)�Bfreetex.c�Afreetex.c�@%tex_shutdowntex.c8�?	%Itex_shutdowntex.cvoid tex_shutdown(tex_t *tex){�>#textex.ctex_t *tex)�=calloctex.c
1�<	Ctex_inittex.c	void tex_init(tex_t **tex){�;%textex.c	tex_t **tex)�:'DestroyWindowsys.cr�9ReleaseDCsys.cq8�8	%Isys_shutdownsys.covoid sys_shutdown(sys_t *sys){�7#syssys.cosys_t *sys)�6sys_errorsys.ck�5GetDCsys.cj�4sys_errorsys.c_�3!ShowWindowsys.c^�2)GetStartupInfosys.c\%�11infosys.c[STARTUPINFO info =�0sys_errorsys.cX�/)CreateWindowExsys.cU�.sys_errorsys.cR�-+RegisterClassExsys.cQ  J ���S1 � � � � � z b J J J J J J J J J J J J J            �
randomtex.h�
purpletex.h�
yellowtex.h�
cyantex.h
�
blacktex.h	�
whitetex.h�
greentex.h�
bluetex.h�
redtex.h�
VID_BPPtex.h�+vid_clear_shadegame.cE�	qgamegame.cvoid game(vid_t *vid,tex_t *tex_root,float tstep){�
#vidgame.cvid_t *vid,(�	-tex_rootgame.ctex_t *tex_root,!�%tstepgame.cfloat tstep)  �7vec2_t__pobr_tag_vid_h_0003vid.h  �7__pobr_tag_vid_h_0003vid.h  �7__pobr_tag_vid_h_0004vid.h  z7#x__pobr_tag_vid_h_0003vid.huint16_t x,  G7'y__pobr_tag_vid_h_0003vid.huint16_t x,y;  7)v__pobr_tag_vid_h_0003vid.huint16_t v[2];   �vid_tvid_svid.h   �vid_svid.h
   �#wvid_svid.huint16_t w,   �'hvid_svid.huint16_t w,h;   a-real_wvid_svid.huint16_t real_w,   4;real_hvid_svid.huint16_t real_w,real_h;
 � > � �F�����O����0&[�A�����4����r� �wUF7(�d ���h�{ ���R � �m= � �^��     +sys_swapbuffers8L%tex_flip_bmp7� �sys8B	main8?tex7�tex7� � sys_init8Ctex_init7�/ stex8Fr8�	size7�%tex_flip_bmp7� rred8�tex7�malloc7�	temp7��tex_init8Gtex7�sys_error7�!sys_update8J
sys_s8Umsg7�strcat7��%sys_shutdown8Msys7�sys_proc7�purple8�
sys_t8V$ msg7�!sys_update7��� random8�sys_error7�sys_error7�sys_error7�sys_error7�sys_init7�sys7�+sys_swapbuffers7�sys7�rec7��� r7h� sys7� sizeoff_min7�b memcpy7�sys_error7�real_w8�real_h8�new_time8rmin_tstep8oz nex	next8�#new_time_648told_time8smemcpy7�off_max7�%sys_shutdown7�� 	old_t#old_time_648umemcpy7�memcpy7�� mememset8
shade8memcpy8malloc7�   tex_l   
main8<malloc8
 @ �fw{ � ���zC� ��&_R��� �0qh_�D��' �n�����6�T �����P��W	��)�6A����                           � vid_shutdown7 
timer8Dvid8@v17�vid_size7�%tex_shutdown7�%tex_shutdown7�L w
white8�%timer_update8I!timer_init8Evid_init8Avid7�� w7�wc7�vid7�vid7�vid7�
timer7�wp7�yellow8�
y_min7�v8�w8�� 
y_max7�y8�w8�%vid_draw_tex7�
width7�x8�
vid_t8�
vid_s8�vid_size7�tex_size7�write_w7�
x_max7�
x_min7�u vid_%vid_shutdown8Ntex_off7��N ye
tex_s8�vid8  
tstep8p
tex_t8�+vid_clear_color8%tex_shutdown8Ovid_size8vid7�vid8	vid_size8+vid_clear_shade8vid8
tstep8�vid8vec2_t8�� h 
timer7�� timer_t8wtimer_s8v�vid8�tex_root8�%vid_shutdown8vid_size8vid_init8
%timer_update7�
timer7�!timer_init7�     	vid_c+vid_clear_shade8�    X �R'���y[;��{T- � � � X                                      (�y/tex_sizevid.csize_t tex_size =(�x1off_maxvid.cuint32_t off_max =(�w1off_minvid.cuint32_t off_min =(�v1write_wvid.cuint32_t write_w =&�u/byte_wvid.cuint32_t byte_w =$�t-x_maxvid.c
uint16_t x_max =$�s-x_minvid.c
uint16_t x_min =$�r-y_maxvid.c	uint16_t y_max =$�q-y_minvid.c	uint16_t y_min =O�p	%wvid_draw_texvid.cvoid vid_draw_tex(vid_t *vid, tex_t *tex, vec2_t v1){�o#vidvid.cvid_t *vid,�n#texvid.ctex_t *tex,�m!v1vid.cvec2_t v1)�l
vid_sizevid.c(�k;QueryPerformanceCountertimer.c>�j	%Qtimer_updatetimer.cvoid timer_update(timer_t *timer){%�i+timertimer.ctimer_t *timer)(�h;QueryPerformanceCountertimer.c*�g?QueryPerformanceFrequencytimer.c
5�f!Afreq_querytimer.cLARGE_INTEGER freq_query =F�e	!etimer_inittimer.cvoid timer_init(timer_t *timer, vid_t *vid){    d ����s[E���\:�����yX. � � � � d                                  %�d+timertimer.ctimer_t *timer,�c#vidtimer.cvid_t *vid)�b%tex_flip_bmptex.cQ�afreetex.cO�`'WebPDecodeBGRtex.cN*�_3dec_datatex.cNuint8_t *dec_data ='�^1heighttex.cMint width, height;�]!widthtex.cMint width,�\fclosetex.cK�[freadtex.cI�Zmalloctex.cH�Yfseektex.cF�Xftelltex.cE�Wfseektex.cD�Vfopentex.c?�U!fptex.c?FILE *fp =�T%datatex.c=void *data =*�S1data_sizetex.c<size_t data_size =�Rcalloctex.c7R�Q	'{tex_load_webptex.c*tex_t *tex_load_webp(tex_t *tex, const char *filename){�P#textex.c*tex_t *tex,,�O7filenametex.c*const char *filename)�Nfreetex.c'�Mmemcpytex.c$�Lmemcpytex.c"�Kmemcpytex.c �Jmalloctex.c�I%temptex.cvoid *temp = �H'sizetex.csize_t size =
   Q ����uoic]WQKE?93-'!��W � � � � ��{uoic]WQK�����������; �����
 �@5*����wj] ���~���                                          8�8�8�8�8�timer_s8w
sys_s8V
sys_s8T8O8N8M8L8K8J8I8H8G8F8E8D8C8B8A8@8?� 
vid_s8�
vid_s8�
vid_s8�8�8�8�8�8�7__pobr_tag_tex_h_00018�7__pobr_tag_tex_h_00018�7__pobr_tag_tex_h_00018�
tex_s8�8�
tex_s8�
tex_s8�
tex_s8�
tex_s8�8�8�8�8�8�8�8�8�8�8�8<8�8�7__pobr_tag_vid_h_00038�7__pobr_tag_vid_h_00038�
vid_s8�8�
vid_s8�
vid_s8�8U
sys_s8S
sys_s8R8Q8P 7__pobr_tag_tex_h_00018�7__pobr_tag_tex_h_00018� 8vtimer_s8utimer_s8ttimer_s8stimer_s8rtimer_s8qtimer_s8ptimer_s8o8n8>8=7__pobr_tag_vid_h_00038�7__pobr_tag_vid_h_00038��  �  � � � �":Ww���:����&@`��� l                                                  �#vidgame.cvid_t *vid,(�z/bmp_sizevid.csize_t bmp_size =�{vid_sizevid.c$�|+bm_offvid.csize_t bm_off =&�}-tex_offvid.csize_t tex_off =�~memcpyvid.c�!cvid.c!color_t c)� #vidvid.c!vid_t *vid,I�	+evid_clear_colorvid.c!void vid_clear_color(vid_t *vid, color_t c){�vid_sizevid.c"�memcpyvid.c#"�)shadevid.c'uint8_t shade)�#vidvid.c'vid_t *vid,L�	+kvid_clear_shadevid.c'void vid_clear_shade(vid_t *vid,uint8_t shade){�memsetvid.c(�vid_sizevid.c(�	#vidvid.c+vid_t *vid)0�
	Avid_initvid.c+void vid_init(vid_t *vid){�mallocvid.c0�vid_sizevid.c0�#vidvid.c3vid_t *vid)8�	%Ivid_shutdownvid.c3void vid_shutdown(vid_t *vid){�freevid.c4   O%tstepgame.cfloat tstep)   +-tex_rootgame.ctex_t *tex_root,� 
 � �\0��b" � g g g g g g g g g g g 9 9 9$�+gflagssys.cuint8_t gflags;Z�		� ~'bmpvid_svid.huint8_t *bmp;� W
VID_BPPvid.h� >'
VID_DEFAULT_Hvid.h� '
VID_DEFAULT_Wvid.h�wtimer_ttimer_stimer.h�vtimer_stimer.h=�u#Aold_time_64timer_stimer.h
LARGE_INTEGER old_time_64;=�t#Anew_time_64timer_stimer.hLARGE_INTEGER new_time_64;/�s+old_timetimer_stimer.hfloat old_time;/�r+new_timetimer_stimer.hfloat new_time;'�q#freqtimer_stimer.hfloat freq;)�p%tsteptimer_stimer.hfloat tstep;1�o-min_tsteptimer_stimer.hfloat min_tstep;�n
TIMER_CPStimer.h  S7color_t__pobr_tag_tex_h_0001tex.h  %7__pobr_tag_tex_h_0001tex.h   �7__pobr_tag_tex_h_0002tex.h   �7!b__pobr_tag_tex_h_0001tex.huint8_t b,   �7%g__pobr_tag_tex_h_0001tex.huint8_t b,g,   q7)r__pobr_tag_tex_h_0001tex.huint8_t b,g,r;   ;73c__pobr_tag_tex_h_0001tex.huint8_t c[VID_BPP];   & ����zX9����zYB& o o o o o o o o o o o o o o o o                                         �tex_ttex_stex.h  �tex_stex.h  �3nexttex_stex.hstruct tex_s *next;  V#wtex_stex.huint16_t w,  3'htex_stex.huint16_t w,h;  'bmptex_stex.huint8_t *bmp;   �
randomtex.h   �
purpletex.h   �
yellowtex.h   �
cyantex.h
   �
blacktex.h	   r
whitetex.h   [
greentex.h   D
bluetex.h   .
redtex.h   
VID_BPPtex.h�Vsys_tsys_ssys.h�Usys_ssys.h�Thwsys_ssys.h	HWND hw;&�S+bmisys_ssys.h
BITMAPINFO bmi;�Rdcsys_ssys.hHDC dc;�Q
GF_RESIZEsys.h�P#
GF_MAINLOOPsys.h�O%tex_shutdownmain.c+�N%vid_shutdownmain.c*�M%sys_shutdownmain.c)�L+sys_swapbuffersmain.c!�Kgamemain.c�J!sys_updatemain.c�I%timer_updatemain.c�HSleepmain.c�Gtex_initmain.c   � ����"C^������������ N N N N N N N                �-'
VID_DEFAULT_Hvid.h�,'
VID_DEFAULT_Wvid.h+�+7color_t__pobr_tag_tex_h_0001tex.h$�*7__pobr_tag_tex_h_0001tg i#vidgame.cvid_t *vid,g H	qgamegame.cvoid game(vid_t *vid,tex_t *tex_root,float tstep){  ;+vid_clear_shadegame.c  7)v__pobr_tag_vid_h_0003vid.huint16_t v[2];   57'y__pobr_tag_vid_h_0003vid.huint16_t x,y;   37#x__pobr_tag_vid_h_0003vid.huint16_t x,   '7__pobr_tag_vid_h_0004vid.h   '7__pobr_tag_vid_h_0003vid.h   -7vec2_t__pobr_tag_vid_h_0003vid.h&�<-gflagsmain.cuint8_t gflags = �=%argvmain.c	char **argv)�>argcmain.c	int argc,3�?	Mmainmain.c	int main(int argc, char **argv){�@#vidmain.cvid_t vid =�Avid_initmain.c�B#sysmain.csys_t sys =�Csys_initmain.c$�D+timermain.ctimer_t timer =�E!timer_initmain.c�F%texmain.ctex_t *tex =    M ���cL0���Y2����_+ � � � � � M                     3�.7)v__pobr_tag_vid_h_0003vid.huint16_t v[2];�-vid_tvid_svid.h�,vid_svid.h
 �+#wvid_svid.huint16_t w,"�*'hvid_svid.huint16_t w,h;*�)-real_wvid_svid.huint16_t real_w,1�(;real_hvid_svid.huint16_t real_w,real_h;$�''bmpvid_svid.huint8_t *bmp;�&
VID_BPPvid.h�%'
VID_DEFAULT_Hvid.h�$'
VID_DEFAULT_Wvid.h+�#7color_t__pobr_tag_tex_h_0001tex.h$�"7__pobr_tag_tex_h_0001tex.h$�!7__pobr_tag_tex_h_0002tex.h/� 7!b__pobr_tag_tex_h_0001tex.huint8_t b,1�7%g__pobr_tag_tex_h_0001tex.huint8_t b,g,3�7)r__pobr_tag_tex_h_0001tex.huint8_t b,g,r;8�73c__pobr_tag_tex_h_0001tex.huint8_t c[VID_BPP];�tex_ttex_stex.h�tex_stex.h+�3nexttex_stex.hstruct tex_s *next; �#wtex_stex.huint16_t w,"�'htex_stex.huint16_t w,h;$�'bmptex_stex.huint8_t *bmp;