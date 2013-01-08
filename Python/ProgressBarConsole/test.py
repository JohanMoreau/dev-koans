# -*- coding: UTF8 -*-



from progressbar import ProgressBar
import time
p = ProgressBar()
for i in range(101):
    p.render(i, 'step %s' % i)
    time.sleep(0.1)

