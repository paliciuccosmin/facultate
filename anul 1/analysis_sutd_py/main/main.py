from q1 import answears_q1 as ans_q1
from q2 import answears_q2 as ans_q2
from q3 import answears_q3 as ans_q3
from q4 import answears_q4 as ans_q4
from q5 import answears_q5 as ans_q5
from q6 import answears_q6 as ans_q6
from q7 import answears_q7 as ans_q7
from q8 import answears_q8 as ans_q8
from have_bachelor import have_bachelor as has_bach
from have_master import have_master as has_master
from have_doctoral import have_doctoral as has_doc
from degree_percentage import *
from question_averages import *
       

def main():
    percentage_bachelor = getBachlorPercentage(has_bach)
    percentage_master = getMastersPercentage(has_master)
    percentage_doctoral = getDoctoralPercentage(has_doc)
    
    # averageQuestion(ans_q4)
    # averageQuestion(ans_q5)
    # averageQuestion(ans_q6)
    # averageQuestion(ans_q7)
    # averageQuestion(ans_q8)
    
    # statisticsTrueFalseDict(ans_q3)
    
    
if __name__ == "__main__":
    main()