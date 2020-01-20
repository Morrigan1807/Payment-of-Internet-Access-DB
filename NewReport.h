#pragma once

namespace PaymentofInternetAccess {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Xml;

	/// <summary>
	/// Сводка для NewReport
	/// </summary>
	public ref class NewReport : public System::Windows::Forms::Form
	{
	public:
		NewReport(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			Report->ColumnCount = 2;
			Report->Rows->Add("Квитанция");
			Report->Rows->Add("Наименование организации:", "ООО \"NoMore\"");
			Report->Rows->Add("Адрес организации:", "ул. Капитальная, д. 18");
			Report->Rows->Add("Телефон организации:", "+375 (29) 999-99-99");
			Report->Rows->Add("Дата:");
			Report->Rows->Add("Время начала и окончания сеанса:");
			Report->Rows->Add("Количество минут:");
			Report->Rows->Add("Стоимость одной минуты:");
			Report->Rows->Add("Итоговая сумма:");
			Report->Rows->Add("ФИО оператора:");
			Report->Rows->Add("Номер смены:");

			
		}
	private: System::Double calc_min_cost(double CPM, double CPM_20_2, double CPM_2_6, int start_minutes, int end_minutes)
	{
		if (end_minutes < start_minutes)
		{
			end_minutes += 1440;
		}
		double total_cost = 0;
		if (start_minutes <= 120)
		{
			if (end_minutes <= 120)
			{
				total_cost += (end_minutes - start_minutes)*CPM_20_2;
			}
			if (120 < end_minutes && end_minutes <= 360)
			{
				total_cost += (120 - start_minutes)*CPM_20_2;
				total_cost += (end_minutes - 120)*CPM_2_6;
			}
			if (120 < end_minutes && end_minutes <= 360)
			{
				total_cost += (120 - start_minutes)*CPM_20_2;
				total_cost += (end_minutes - 120)*CPM_2_6;
			}
			if (360 < end_minutes && end_minutes <= 1200)
			{
				total_cost += (120 - start_minutes)*CPM_20_2;
				total_cost += (360 - 120)*CPM_2_6;
				total_cost += (end_minutes - 360)*CPM;
			}
			if (1200 < end_minutes)
			{
				total_cost += (120 - start_minutes)*CPM_20_2;
				total_cost += (360 - 120)*CPM_2_6;
				total_cost += (1200 - 360)*CPM;
				total_cost += (end_minutes - 1200)*CPM_20_2;
			}
		}
		if (120 < start_minutes && start_minutes <= 360)
		{
			if (120 < end_minutes && end_minutes <= 360)
			{
				total_cost += (end_minutes - start_minutes)*CPM_2_6;
			}
			if (360 < end_minutes && end_minutes <= 1200)
			{
				total_cost += (360 - start_minutes)*CPM_2_6;
				total_cost += (end_minutes - 360)*CPM;
			}
			if (1200 < end_minutes && end_minutes <= 1560)
			{
				total_cost += (360 - start_minutes)*CPM_2_6;
				total_cost += (1200 - 360)*CPM;
				total_cost += (end_minutes - 1200)*CPM_20_2;
			}
			if (1560 < end_minutes)
			{
				total_cost += (360 - start_minutes)*CPM_2_6;
				total_cost += (1200 - 360)*CPM;
				total_cost += (1560 - 1200)*CPM_20_2;
				total_cost += (end_minutes - 1560)*CPM_2_6;
			}
		}
		if (360 < start_minutes && start_minutes <= 1200)
		{
			if (360 < end_minutes && end_minutes <= 1200)
			{
				total_cost += (end_minutes - start_minutes)*CPM;
			}
			if (1200 < end_minutes && end_minutes <= 1560)
			{
				total_cost += (1200 - start_minutes)*CPM;
				total_cost += (end_minutes - 1200)*CPM_20_2;
			}
			if (1560 < end_minutes && end_minutes <= 1800)
			{
				total_cost += (1200 - start_minutes)*CPM;
				total_cost += (1560 - 1200)*CPM_20_2;
				total_cost += (end_minutes - 1560)*CPM_2_6;
			}
			if (1800 < end_minutes)
			{
				total_cost += (1200 - start_minutes)*CPM;
				total_cost += (1560 - 1200)*CPM_20_2;
				total_cost += (1800 - 1560)*CPM_2_6;
				total_cost += (end_minutes - 1800)*CPM;
			}
		}
		if (1200 < start_minutes)
		{
			if (1200 < end_minutes && end_minutes <= 1560)
			{
				total_cost += (end_minutes - start_minutes)*CPM_20_2;
			}
			if (1560 < end_minutes && end_minutes <= 1800)
			{
				total_cost += (1560 - start_minutes)*CPM;
				total_cost += (end_minutes - 1560)*CPM_20_2;
			}
			if (1800 < end_minutes && end_minutes <= 2640)
			{
				total_cost += (1560 - start_minutes)*CPM;
				total_cost += (2640 - 1560)*CPM_20_2;
				total_cost += (end_minutes - 2640)*CPM_2_6;
			}
			if (2640 < end_minutes)
			{
				total_cost += (1560 - start_minutes)*CPM;
				total_cost += (1800 - 1560)*CPM_20_2;
				total_cost += (2640 - 1800)*CPM_2_6;
				total_cost += (end_minutes - 2640)*CPM;
			}
		}
		return total_cost / (end_minutes - start_minutes);
	}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~NewReport()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::DateTimePicker^  Seance_date;
	private: System::Windows::Forms::ComboBox^  Computer_number;
	private: System::Windows::Forms::DateTimePicker^  DT_start;
	private: System::Windows::Forms::DateTimePicker^  DT_end;
	private: System::Windows::Forms::Button^  Add_seance;
	private: System::Windows::Forms::DataGridView^  Report;

	public: Form^ general;
			int user = 0;
			int num_of_mins = 0;
			double cost_min = 0;



	private: System::Windows::Forms::Button^  Print_report;
	private: System::Windows::Forms::Button^  exit;
	private: System::Windows::Forms::ComboBox^  Connection_number;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ToolTip^  toolTip1;
private: System::Drawing::Printing::PrintDocument^  printDocument1;
private: System::Windows::Forms::PrintDialog^  printDialog1;

	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(NewReport::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Seance_date = (gcnew System::Windows::Forms::DateTimePicker());
			this->Computer_number = (gcnew System::Windows::Forms::ComboBox());
			this->DT_start = (gcnew System::Windows::Forms::DateTimePicker());
			this->DT_end = (gcnew System::Windows::Forms::DateTimePicker());
			this->Add_seance = (gcnew System::Windows::Forms::Button());
			this->Report = (gcnew System::Windows::Forms::DataGridView());
			this->Print_report = (gcnew System::Windows::Forms::Button());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->Connection_number = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());
			this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Report))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(403, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Веберите дату:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(403, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(161, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Выберите номер компьютера:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(403, 178);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(208, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Время начала выбранного соединения:";
			this->toolTip1->SetToolTip(this->label3, L"Это поле заполняется автоматически.");
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Location = System::Drawing::Point(403, 228);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(226, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Время окончания выбранного соединения:";
			this->toolTip1->SetToolTip(this->label4, L"Это поле заполняется автоматически.");
			// 
			// Seance_date
			// 
			this->Seance_date->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->Seance_date->Location = System::Drawing::Point(406, 42);
			this->Seance_date->Name = L"Seance_date";
			this->Seance_date->Size = System::Drawing::Size(223, 20);
			this->Seance_date->TabIndex = 5;
			this->Seance_date->ValueChanged += gcnew System::EventHandler(this, &NewReport::Seance_date_ValueChanged);
			// 
			// Computer_number
			// 
			this->Computer_number->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Computer_number->Location = System::Drawing::Point(406, 94);
			this->Computer_number->Name = L"Computer_number";
			this->Computer_number->Size = System::Drawing::Size(223, 21);
			this->Computer_number->TabIndex = 6;
			this->Computer_number->SelectionChangeCommitted += gcnew System::EventHandler(this, &NewReport::Computer_number_SelectionChangeCommitted);
			// 
			// DT_start
			// 
			this->DT_start->CustomFormat = L"HH:mm:ss";
			this->DT_start->Enabled = false;
			this->DT_start->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->DT_start->Location = System::Drawing::Point(406, 194);
			this->DT_start->Name = L"DT_start";
			this->DT_start->Size = System::Drawing::Size(223, 20);
			this->DT_start->TabIndex = 7;
			this->toolTip1->SetToolTip(this->DT_start, L"Это поле заполняется автоматически.");
			// 
			// DT_end
			// 
			this->DT_end->CustomFormat = L"HH:mm:ss";
			this->DT_end->Enabled = false;
			this->DT_end->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->DT_end->Location = System::Drawing::Point(406, 244);
			this->DT_end->Name = L"DT_end";
			this->DT_end->Size = System::Drawing::Size(223, 20);
			this->DT_end->TabIndex = 8;
			this->toolTip1->SetToolTip(this->DT_end, L"Это поле заполняется автоматически.");
			// 
			// Add_seance
			// 
			this->Add_seance->Location = System::Drawing::Point(406, 287);
			this->Add_seance->Name = L"Add_seance";
			this->Add_seance->Size = System::Drawing::Size(200, 34);
			this->Add_seance->TabIndex = 9;
			this->Add_seance->Text = L"Добавить сеанс в отчет";
			this->Add_seance->UseVisualStyleBackColor = true;
			this->Add_seance->Click += gcnew System::EventHandler(this, &NewReport::Add_seance_Click);
			// 
			// Report
			// 
			this->Report->AllowUserToAddRows = false;
			this->Report->AllowUserToDeleteRows = false;
			this->Report->AllowUserToResizeColumns = false;
			this->Report->AllowUserToResizeRows = false;
			this->Report->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->Report->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->Report->BackgroundColor = System::Drawing::Color::White;
			this->Report->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Report->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::Disable;
			this->Report->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->Report->ColumnHeadersVisible = false;
			this->Report->Enabled = false;
			this->Report->Location = System::Drawing::Point(12, 12);
			this->Report->MultiSelect = false;
			this->Report->Name = L"Report";
			this->Report->RowHeadersVisible = false;
			this->Report->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->Report->Size = System::Drawing::Size(362, 429);
			this->Report->TabIndex = 10;
			// 
			// Print_report
			// 
			this->Print_report->Location = System::Drawing::Point(427, 348);
			this->Print_report->Name = L"Print_report";
			this->Print_report->Size = System::Drawing::Size(148, 25);
			this->Print_report->TabIndex = 11;
			this->Print_report->Text = L"Печать квитанции";
			this->Print_report->UseVisualStyleBackColor = true;
			this->Print_report->Click += gcnew System::EventHandler(this, &NewReport::Print_report_Click);
			// 
			// exit
			// 
			this->exit->Location = System::Drawing::Point(579, 418);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(75, 23);
			this->exit->TabIndex = 12;
			this->exit->Text = L"Выход";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &NewReport::exit_Click);
			// 
			// Connection_number
			// 
			this->Connection_number->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Connection_number->Location = System::Drawing::Point(406, 142);
			this->Connection_number->Name = L"Connection_number";
			this->Connection_number->Size = System::Drawing::Size(223, 21);
			this->Connection_number->TabIndex = 13;
			this->Connection_number->SelectionChangeCommitted += gcnew System::EventHandler(this, &NewReport::Connection_number_SelectionChangeCommitted);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Location = System::Drawing::Point(403, 126);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(158, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Выберите номер соединения:";
			// 
			// printDocument1
			// 
			this->printDocument1->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &NewReport::printDocument1_PrintPage);
			// 
			// printDialog1
			// 
			this->printDialog1->UseEXDialog = true;
			// 
			// NewReport
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(666, 453);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Connection_number);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->Print_report);
			this->Controls->Add(this->Report);
			this->Controls->Add(this->Add_seance);
			this->Controls->Add(this->DT_end);
			this->Controls->Add(this->DT_start);
			this->Controls->Add(this->Computer_number);
			this->Controls->Add(this->Seance_date);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"NewReport";
			this->Text = L"Создание квитанции";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &NewReport::NewReport_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Report))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		general->Enabled = true;
		this->Close();
	}
private: System::Void NewReport_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
{
	general->Enabled = true;
}
private: System::Void Seance_date_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	this->Computer_number->Items->Clear();
	String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
	SqlConnection^ connect = gcnew SqlConnection(db);
	SqlCommand^ command = connect->CreateCommand();
	command->CommandText = "SELECT DISTINCT Computer_number From Seance WHERE S_date = CONVERT(DATE, \'" + Seance_date->Text->ToString()
		+ "\', 104) AND Operator_number = " + Convert::ToString(user);
	command->Connection = connect;
	SqlDataReader^ dr;
	connect->Open();
	dr = command->ExecuteReader();
	while (dr->Read())
	{
		this->Computer_number->Items->Add(dr[0]);
	}
	dr->Close();
	connect->Close();
}
private: System::Void Computer_number_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) 
{
	this->Connection_number->Items->Clear();
	String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
	SqlConnection^ connect = gcnew SqlConnection(db);
	SqlCommand^ command = connect->CreateCommand();
	command->CommandText = "SELECT DISTINCT ID_connection FROM Seance WHERE Computer_number = " + ((ComboBox^)sender)->SelectedItem->ToString()
		+ " AND Operator_number = " + Convert::ToString(user);
	command->Connection = connect;
	SqlDataReader^ dr;
	connect->Open();
	dr = command->ExecuteReader();
	while (dr->Read())
	{
		this->Connection_number->Items->Add(dr[0]);
	}
	dr->Close();
	connect->Close();
}
private: System::Void Connection_number_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) 
{
	String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
	SqlConnection^ connect = gcnew SqlConnection(db);
	SqlCommand^ command = connect->CreateCommand();
	command->CommandText = "SELECT T_start, T_end From Connections WHERE ID_connection = " + ((ComboBox^)sender)->SelectedItem->ToString();
	command->Connection = connect;
	SqlDataReader^ dr;
	connect->Open();
	dr = command->ExecuteReader();
	while (dr->Read())
	{
		this->DT_start->Text = dr[0]->ToString();
		this->DT_end->Text = dr[1]->ToString();
	}
	dr->Close();
	connect->Close();
}
private: System::Void Add_seance_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (Seance_date->Text->ToString() != "" && Computer_number->Text->ToString() != "" && Connection_number->Text->ToString() != "")
	{
		if (Computer_number->Text->ToString() != "" && Connection_number->Text->ToString() != "")
		{
			Report->Rows[4]->Cells[1]->Value = "";
			Report->Rows[5]->Cells[1]->Value = "";
			Report->Rows[6]->Cells[1]->Value = "";
			Report->Rows[7]->Cells[1]->Value = "";
			Report->Rows[8]->Cells[1]->Value = "";
			Report->Rows[9]->Cells[1]->Value = "";
			Report->Rows[10]->Cells[1]->Value = "";

			Report->Rows[4]->Cells[1]->Value = Seance_date->Text->ToString();
			Report->Rows[5]->Cells[1]->Value = DT_start->Text->ToString() + " - " + DT_end->Text->ToString();
			String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
			SqlConnection^ connect = gcnew SqlConnection(db);
			SqlCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT Num_of_min From Connections WHERE ID_connection = " + Connection_number->Text->ToString();
			command->Connection = connect;
			SqlDataReader^ dr;
			connect->Open();
			dr = command->ExecuteReader();
			dr->Read();
			Report->Rows[6]->Cells[1]->Value = dr[0]->ToString();
			num_of_mins += Convert::ToInt32(dr[0]);
			dr->Close();
			command->CommandText = "SELECT CPM, CPM_20_2, CPM_2_6 From Seance JOIN Prices ON Seance.ID_price = Prices.ID_price "
				+ "WHERE Computer_number = " + Computer_number->Text->ToString() + " AND S_date = CONVERT(DATE,\ '" + Seance_date->Text->ToString()
				+ "\', 104) AND ID_connection = " + Connection_number->Text->ToString();
			dr = command->ExecuteReader();
			dr->Read();
			cost_min = calc_min_cost(Convert::ToDouble(dr[0]), Convert::ToDouble(dr[1]), Convert::ToDouble(dr[2]),
				Convert::ToInt32(Convert::ToDateTime(DT_start->Text).TimeOfDay.TotalMinutes),
				Convert::ToInt32(Convert::ToDateTime(DT_end->Text).TimeOfDay.TotalMinutes));
			Report->Rows[7]->Cells[1]->Value = Convert::ToString(cost_min);
			dr->Close();
			Report->Rows[8]->Cells[1]->Value = Convert::ToString(num_of_mins * cost_min);
			command->CommandText = "SELECT Full_name FROM Operators WHERE Operator_number = " + Convert::ToString(user);
			dr = command->ExecuteReader();
			dr->Read();
			Report->Rows[9]->Cells[1]->Value = dr[0]->ToString();
			dr->Close();
			command->CommandText = "SELECT Shift_number From Seance JOIN Shifts ON Seance.ID_shift = Shifts.ID_shift "
				+ "WHERE Computer_number = " + Computer_number->Text->ToString() + " AND S_date = CONVERT(DATE,\ '" + Seance_date->Text->ToString()
				+ "\', 104) AND ID_connection = " + Connection_number->Text->ToString();
			dr = command->ExecuteReader();
			dr->Read();
			Report->Rows[10]->Cells[1]->Value = dr[0]->ToString();
			dr->Close();
			connect->Close();
		}
		else
		{
			MessageBox::Show("Ошибка! Необходимо заполнить все строки!");
		}
	}
}
private: System::Void printDocument1_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) 
{
	Bitmap^ bmp = gcnew Bitmap(Report->Size.Width + 10, Report->Size.Height + 10);
	Report->DrawToBitmap(bmp, Report->Bounds);
	e->Graphics->DrawImage(bmp, 0, 0);
}
private: System::Void Print_report_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (printDialog1->ShowDialog() == System::Windows::Forms::DialogResult(1))
	{
		Report->ClearSelection();
		printDocument1->PrinterSettings = printDialog1->PrinterSettings;
		printDocument1->Print();
	}
}
};
}