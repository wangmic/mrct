# About MRCT

MRCT is a program could find hub structure and coexpression module.

More information related the method, see [this link](https://github.com/zy26/MRHCA).
 
For the R codes which could reproduce the result of "MRHCA: A nonparametric statistics based method for hub and co-expression module identification in large gene co-expression network", see [this link](https://github.com/zy26/MRHCA-R).

# How  to clone the codes

```
git clone --recursive https://github.com/zy26/mrct.git
```

Or, you can just click **Clone or download** under the repository name, then put the code files of ```libmrct``` to ```lib``` dir.

# How to compile and run the program?

## Linux

```
g++ -std=c++11 -fopenmp -O3 lib/*.cc src/*.cc
```

```
./a.out testdata/E_coli_anaerobic.txt E_coli_anaerobic.output.txt 1
```

## Windows

Use Visual Studio project file ```mrct.vcxproj``` inside. You may need [modify the Platform Toolset](https://docs.microsoft.com/cpp/build/how-to-modify-the-target-framework-and-platform-toolset) to the version on your PC. 

The Command Arguments should be ```testdata/E_coli_anaerobic.txt E_coli_anaerobic.output.txt 1```, or you can use your file name instead.

Warning: Try to avoid **Debug** mode, it may be very slow.

# What does the output mean?

You will see the content of output file as below somehow.

```
1	327	0
1	0	1501
1	252	0
1	368	0
1	201	0
1	239	0
1	247	0
1	288	0
1	224	0
1	0	761
1	209	0
1	228	0
1	0	1265
1	0	1253
1	0	1232
1	0	942
1	0	813
1	0	738
1	0	1016
1	212	0
1	206	0
1	0	1447
1	0	1559
1	0	1406
1	0	792
1	137	0
1	0	1481
1	331	0
1	0	1282
1	0	840
1	0	1314
1	0	1124
1	210	0
1	0	1528
1	0	1052
1	0	1639
1	0	1359
1	0	1139
1	0	1458
1	0	1426
1	0	937
1	218	0
1	231	0
1	0	1589
1	0	1325
1	0	1273
1	374	0
1	0	901
1	0	865
1	214	0
1	201	0
1	237	0
1	233	0
1	308	0
1	0	1289
1	0	1417
1	0	1228
1	0	1382
1	199	0
1	289	0
1	219	0
1	0	975
1	0	1344
1	0	951
1	0	1284
1	289	0
1	236	0
1	0	1293
1	298	0
1	366	0
1	0	819
1	0	1160
1	0	799
1	0	885
1	0	1162
1	0	1078
1	0	1496
1	0	1330
1	0	1030
1	177	0
1	139	0
1	0	1164
1	0	1414
1	0	933
1	0	876
1	0	1365
1	254	0
1	0	1433
1	0	1462
1	0	1406
1	0	1512
1	0	1116
1	0	1310
1	0	1406
1	0	1305
1	0	1170
1	0	1583
1	0	1086
1	0	1340
1	0	1301
1	0	1315
1	0	1175
1	354	0
1	0	1174
1	291	0
1	0	781
1	0	1254
1	131	0
1	0	1480
1	0	1134
1	221	0
1	207	0
1	211	0
1	0	784
1	0	1395
1	0	1314
1	0	1392
1	0	1409
1	219	0
1	223	0
1	0	932
1	0	1136
1	0	1208
1	0	1547
1	131	0
1	0	816
1	0	848
1	309	0
1	0	768
1	0	791
1	0	977
1	357	0
1	324	0
1	0	1532
1	0	1230
1	0	881
1	0	1342
1	0	1520
1	0	1119
1	0	768
1	0	801
1	0	896
1	0	1068
1	141	0
1	0	773
1	0	1121
1	139	0
1	0	834
1	364	0
1	0	786
1	0	1200
1	0	805
1	0	840
1	0	1077
1	183	0
1	0	1077
1	0	979
1	318	0
1	0	779
1	0	972
1	0	969
1	315	0
1	0	853
1	343	0
1	0	1188
1	373	0
1	0	836
1	222	0
1	0	1198
1	0	1070
1	0	1171
1	233	0
1	0	781
1	0	1367
1	0	1051
1	0	1234
1	0	1386
1	0	1374
1	0	1087
1	0	1549
1	0	849
1	0	1506
1	371	0
1	0	781
1	0	736
1	0	844
1	0	779
1	0	977
1	0	924
1	0	1315
1	0	1025
1	0	1101
1	0	1179
1	0	1245
```

That means: We find 194 hubs. The second column is the cluster bound of the cluster. The last column is the index of the original rows in the matrix of the input file. 
