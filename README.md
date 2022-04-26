<p align="center">
  <img src="logo/sherloq.png" width="600px" alt="Sherloq" />
  <br><b>オープンソースな画像解析ツールセット</b>
</p>

# はじめに
"*法医学的画像解析とは、画像科学と専門知識を駆使し、法的な問題において画像の内容や画像そのものを解析することです。法執行機関で利用される画像解析の主なサブディシプリンは写真測量、写真比較、コンテンツ分析、画像認証の４つです。*" (画像技術に関する科学ワーキンググループより)

**Sherloq**は、デジタル画像解析のための完全に統合された環境を実装するための個人的な研究プロジェクトです。これは、画像が偽造されたものかどうかを判断するツール（そんなツールはおそらく存在しないでしょう...）としてではなく、最新の研究論文やワークショップで見つかった様々なアルゴリズムを実験するためのコンパニオンとして開発されています。
多くの市販のプログラムは値段が非常に高く、法執行機関や政府機関のみに提供されることが多いのですが、このツールセットは拡張可能なフレームワークであると同時に、画像処理のためのアプリケーションを誰でも利用できるようにしています。

私は、*不確実性*は、あらゆる種類の画像解析ツールセットを提供する時の間違った方法だと考えています（例えば、「この独自のソフトウェアを使えば、この写真が*本物であることを証明します...そして、あなたは私を信じてください!」）。オープンソースの理念に基づき、誰もが様々な技術を自分で試し、知識を得て、それをコミュニティで共有できるようにすべきです...コードの改善に貢献するなら、なおさらです。

- [沿革](https://github.com/GuidoBartoli/sherloq#historry)
- [機能](https://github.com/GuidoBartoli/sherloq#features)
- [スクリーンショット](https://github.com/GuidoBartoli/sherloq#screenshots)
- [インストール方法](https://github.com/GuidoBartoli/sherloq#installation)
- [アップデート](https://github.com/GuidoBartoli/sherloq#updates)
- [参考文献](https://github.com/GuidoBartoli/sherloq#bibliography)

# 沿革
最初のバージョンは、多くのオプションを持つコマンドラインユーティリティを構築するためにC++11を使って2015年に書かれましたが、すぐに面倒くさくなって効率的でないことが判明しました。 そのバージョンは、OpenCV、Boost、AlgLibのライブラリをインストールした後、CMakeでコンパイルすることができました。 この最初の実証実験では、予定していた機能の約8割を提供しました。(詳しくは下記をご覧ください。).

新たなアルゴリズムも盛り込みつつ、2017年リリースのバージョンでは主にQtベースのマルチウィンドウGUIを追加し、より良いユーザーエクスペリエンスを提供することに成功しました。複数の解析結果を画面に表示することができ、高速ズーム/スクロールビューアも実装され、画像のナビゲーションが容易になりました。そのプロジェクトはQt CreatorでQt 5とOpenCV 3でコンパイルすることができ、予定していた機能の７割程度を実装することができました。
2020年リリースのバージョンでは、開発とデプロイを容易にするために、すべてをPython（PySide2 + Matplotlib + OpenCV）で移植することにしました。 この挑戦は始まったばかりで、まだ以前のコードをすべて新しいプラットフォームに移植していませんが、これがプロジェクトの最終的な「形」になると思います（誰かが素敵なウェブアプリケーションを開発するためにボランティアで参加しない限りはね！）。

私は、このコードを共有し、改善やテストをしようと考えている方を歓迎しています。しかし、このリポジトリは最終的な製品を配布するためのものではないことを心に留めておいてください、私の目的は、*安価な教育ツール*の開発をトラッキングするだけですので、バグや洗練されていないコード、足りない機能の追加を期待しています。

# 特徴
このリストには、ベータ版の段階でこのライブラリが提供する（と期待される）機能が含まれています。 (**NOTE:** プログラム中にイタリック体で表示されている関数は、まだ実装されていません。).

## Interface
- Modern Qt-based GUI with multiple tool window management
- Support for many formats (JPEG, PNG, TIFF, BMP, WebP, PGM, PFM, GIF)
- Highly responsive image viewer with real-time pan and zoom
- Many state-of-the-art algorithms to try out interactively
- Export both visual and textual results of the analysis
- Extensive online help with explanations and tutorials

## Tools

### General
- __Original Image__: display the unaltered reference image for visual inspection
- __File Digest__: retrieve physical file information, crypto and perceptual hashes
- __Hex Editor__: open an external hexadecimal editor to show and edit raw bytes
- __Similar Search__: browse online search services to find visually similar images

### Metadata
- __Header Structure__: dump the file header structure and display an interactive view
- __EXIF Full Dump__: scan through file metadata and gather all available information
- __Thumbnail Analysis__: extract optional embedded thumbnail and compare with original
- __Geolocation Data__: retrieve optional geolocation data and show it on a world map

### Inspection
- __Enhancing Magnifier__: magnifying glass with enhancements for better identifying forgeries
- __Channel Histogram__: display single color channels or RGB composite interactive histogram
- __Global Adjustments__: apply standard image adjustments (brightness, hue, saturation, ...)
- __Reference Comparison__: open a synchronized double view for comparison with another picture

### Detail
- __Luminance Gradient__: analyze horizontal/vertical brightness variations across the image
- __Echo Edge Filter__: use derivative filters to reveal artificial out-of-focus regions
- __Wavelet Threshold__: reconstruct image with different wavelet coefficient thresholds
- __Frequency Split__: split image luminance into high and low frequency components

### Colors
- __RGB/HSV Plots__: display interactive 2D and 3D plots of RGB and HSV pixel values
- __Space Conversion__: convert RGB channels into HSV/YCbCr/Lab/Luv/CMYK/Gray spaces
- __PCA Projection__: use color PCA to project pixel onto most salient components
- __Pixel Statistics__: compute minimum/maximum/average RGB values for every pixel

### Noise
- __Noise Separation__: estimate and extract different kind of image noise components
- __Min/Max Deviation__: highlight pixels deviating from block-based min/max statistics
- __Bit Planes Values__: show individual bit planes to find inconsistent noise patterns
- __PRNU Identification__: exploit sensor pattern noise introduced by different cameras

### JPEG
- __Quality Estimation__: extract quantization tables and estimate last saved JPEG quality
- __Error Level Analysis__: show pixel-level difference against fixed compression levels
- __Multiple Compression__: use a machine learning model to detect multiple compression
- __JPEG Ghost Maps__: highlight traces of different compression levels in difference images

### Tampering
- __Contrast Enhancement__: analyze color distribution to detect contrast enhancements
- __Copy-Move Forgery__: use invariant feature descriptors for cloned area detection
- __Composite Splicing__: exploit DCT statistics for automatic splicing zone detection
- __Image Resampling__: estimate 2D pixel interpolation for detecting resampling traces

### Various
- __Median Filtering__: detect processing traces left by nonlinear median filtering
- __Illuminant Map__: estimate scene local light direction on estimated 3D surfaces
- __Dead/Hot Pixels__: detect and fix dead/hot pixels caused by sensor imperfections
- __Stereogram Decoder__: decode 3D images concealed in crossed-eye autostereograms


# Screenshots
Here are some screenshots from the previous C++ Qt GUI (to be updated with the new version):
<p align="center">
  <img src="screenshots/File.jpg" alt="File Analysis"/>
  <br><b>File Analysis</b>: Metadata, Digest and EXIF
</p>

<p align="center">
  <img src="screenshots/Color.jpg" alt="Color Analysis"/>
  <br><b>Color Analysis</b>: Space Conversion, PCA Projection, Histograms and Statistics
</p>

<p align="center">
  <img src="screenshots/Visual.jpg" alt="Visual Inspection"/>
  <br><b>Visual Inspection</b>: Magnifier Loupe, Image Adjustments and Evidence Comparison
</p>

<p align="center">
  <img src="screenshots/JPEG.jpg" alt="JPEG Analysis"/>
  <br><b>JPEG Analysis</b>: Quantization Tables, Compression Ghosts and Error Level Analysis
</p>

<p align="center">
  <img src="screenshots/LumaNoise.jpg" alt="Luminance/Noise"/>
  <br><b>Luminance and Noise</b>: Light Gradient, Echo Edge, Min/Max Deviation and SNR Consistency
</p>

# Installation

For more information about Python Virtual Environments, you can read [here](https://realpython.com/python-virtual-environments-a-primer/) or [here](https://chriswarrick.com/blog/2018/09/04/python-virtual-environments/).

## [1/2] Virtual environment

### Linux
```
$ sudo apt install python3-distutils python3-dev python3-testresources subversion
$ wget https://bootstrap.pypa.io/get-pip.py
$ sudo python3 get-pip.py
$ sudo pip install virtualenv virtualenvwrapper
$ echo -e "\n# Python Virtual Environments" >> ~/.bashrc
$ echo "export WORKON_HOME=$HOME/.virtualenvs" >> ~/.bashrc
$ echo "export VIRTUALENVWRAPPER_PYTHON=/usr/bin/python3" >> ~/.bashrc
$ echo "source /usr/local/bin/virtualenvwrapper.sh" >> ~/.bashrc
$ source ~/.bashrc
$ mkvirtualenv sq -p python3
```

### MacOS

1) Open Terminal and enter `python3 --version` to install the interpreter and other command line tools
2) Once installed, proceed similarly to Linux installation:
```
   $ wget https://bootstrap.pypa.io/get-pip.py
   $ sudo python3 get-pip.py
   $ sudo pip install virtualenv virtualenvwrapper
   $ echo -e "\n# Python Virtual Environments" >> ~/.bash_profile
   $ echo "export WORKON_HOME=$HOME/.virtualenvs" >> ~/.bash_profile
   $ echo "export VIRTUALENVWRAPPER_PYTHON=/usr/bin/python3" >> ~/.bash_profile
   $ echo "source /usr/local/bin/virtualenvwrapper.sh" >> ~/.bash_profile
   $ source ~/.bash_profile
```
3) Create a new Python 3 virtual environment:
```
$ mkvirtualenv sq -p python3
```
4) Install `libmagic` via `brew` (thanks to @thmsl):
```
   $ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   $ brew install libmagic
```

### Windows
1. Download latest *Python* setup package from [official site](https://www.python.org/downloads/)
1. Install ensuring that "Add Python to PATH" and "PIP installation" are enabled
1. Open *Command Prompt* and enter the following commands:
```
> pip install virtualenv virtualenvwrapper-win
> mkvirtualenv sq
```

### Conda
1. Download and install [Anaconda](https://www.anaconda.com/products/individual) (one can also install miniconda, no GUI but is smaller)
1. Install Xinerama library: `sudo apt-get install libxcb-xinerama0`
1. Open a console to create a Python environment (on Windows one must start a Conda Console or `sth` from the Start menu):
`conda create --copy -n sherloq python` [enter *Yes* when it prompts]
1. After install ends, type in the same console `conda activate sherloq` to activate the environment 

## [2/2] Launch program
1. Clone the repository content into a local folder
1. Change current directory to the `gui` folder inside `sherloq`
1. Execute `pip install -r requirements.txt` to install required packages (use `pip install -r requirements_win.txt` on Windows)
1. Launch the GUI with `python sherloq.py`

# Updates
When a new version is released, update the local working copy using Git, SVN or manually downloading from this repository and (if necessary) update the packages in the virtual environment following [this guide](https://www.activestate.com/resources/quick-reads/how-to-update-all-python-packages/).

# Bibliography
- "A Picture's Worth: Digital Image Analysis and Forensics" (Neal Krawetz) [[paper](http://blackhat.com/presentations/bh-dc-08/Krawetz/Whitepaper/bh-dc-08-krawetz-WP.pdf)]
- "Noiseprint: a CNN-based camera model fingerprint" (Davide Cozzolino, Luisa Verdoliva) [[website](http://www.grip.unina.it/research/83-multimedia_forensics/107-noiseprint.html)]
- "Exposing Digital Forgeries by Detecting Traces of Re-sampling" (Alin C. Popescu and Hany Farid) [[paper](https://farid.berkeley.edu/downloads/publications/sp05.pdf)]
- "Two Improved Forensic Methods of Detecting Contrast Enhancement in Digital Images" (Xufeng Lin, Xingjie Wei and Chang-Tsun Li) [[paper](https://d1wqtxts1xzle7.cloudfront.net/45863267/Two_Improved_Forensic_Methods_of_Detecti20160522-6998-1xf1cu.pdf?1463954131=&response-content-disposition=inline%3B+filename%3DTwo_improved_forensic_methods_of_detecti.pdf&Expires=1598306603&Signature=dYuKum8UF2NJS~2Jz2pFObtzdjKfYIcYD4GksLVNN0izhm2k10TVPV~UHKS0DbMLXKaurZPq7uvG~qQwQwwF4JKbY0zoCqZI-p9KZsEMYhlRJrYM8nNQL0V7sHMTLd3aYjNLWup~-i1RzJcJdRqzjU9doGxRJvHdsX6tbwIxNRq3JiYyldaXei4xJSJAbX7EoUOut2uh~jsPnsAbDOIrYpwUhebut-XsN2c5MXargD2UhKxZ3Ifwo4hJvz8Bl2sPys~E8P6vDlqOeEHoeByZms6JQON97EGsCTT5GYF98rQLDbqj0NroYE2zDMGcu9IUp8VV1Fotqci1G6eELTXx6w__&Key-Pair-Id=APKAJLOHF5GGSLRBV4ZA)]

